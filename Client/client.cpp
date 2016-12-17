#include "client.h"
#include "ui_client.h"

#include <QFileDialog>
#include<QStringList>
#include <QThread>

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};
Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{

    ui->setupUi(this);

    this->clientSocket = new QTcpSocket();
    this->udpSocket = new QUdpSocket();
    ui->localPortLineEdit->setText("1111");
    ui->serverIPLineEdit->setText("127.0.0.1");
    ui->serverPortLineEdit->setText("9999");
    ui->usernameLineEdit->setText("jnhj");
    this->interfacesIPsQListInitialized=false;

    this->clientsUsernamesOnlineQList = QList<QString>();
    this->clientsAddressesOnlineQList = QList<QHostAddress>();
    this->clientsPortsOnlineQList = QList<quint16>();


    connect(this->clientSocket,SIGNAL(connected()),this,SLOT(connected()));
    connect(this->clientSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(this->clientSocket,SIGNAL(readyRead()),this,SLOT(readyReadQTcpSocket()));


    connect(this->udpSocket,SIGNAL(readyRead()),this,SLOT(readyReadQUdpSocket()));
    //connect(this->udpSocket,SIGNAL(readyRead()),this,SLOT(listenfile()));

    this->getInterfaces();

}

Client::~Client()
{
    this->clientSocket->close();
    delete ui;
}


void Client::on_fileButton_clicked(){
    bytes.clear();
    ui->progressBar->setValue(0);
    QFile file1(QFileDialog::getOpenFileName(NULL, tr("Select a file")));
    file1.open(QIODevice::ReadOnly);
    bytes = file1.readAll();
    file1.close();
    QString q = "@@@file@@@/"+QString::number(bytes.size())+"/";
    qDebug()<<bytes.size();
    QByteArray bufferSent = q.toUtf8();
    bufferSent.append(file1.fileName().toUtf8());
    udpSocket->writeDatagram(bufferSent,QHostAddress(peerRemoteIP),peerRemotePort);
     //quint16 crc1;
    c=0;
    sendFile();

}
void Client::sendFile(){
    Sleeper::sleep(1);

    sendSub(0);

    while(true){
        qDebug()<<"c"<<c-1;
        qDebug()<<"filesize"<<bytes.size();

        if((c-1)==bytes.size()){
            qDebug()<<"finished";
            QString q = "@@@finished@@@/";
            QByteArray bufferSent = q.toUtf8();
            udpSocket->writeDatagram(bufferSent, QHostAddress(peerRemoteIP), peerRemotePort);
            break;

        }
        qDebug()<<"c"<<c;
        while(ackRe){
            ackRe = false;
            if(ack == true){
                qDebug()<<"send new ";
                sendSub(0);
            }
            else if(ack == false){
                qDebug()<<"resend";
               sendSub(1);
            }
        }
    }

}
void Client::sendSub(int s){
    //s==0 send new data ////s==1 resend last packet
    if(s==1){
        udpSocket->writeDatagram(checksumBuffer,QHostAddress(peerRemoteIP),peerRemotePort);
        udpSocket->writeDatagram(subbytes, QHostAddress(peerRemoteIP), peerRemotePort);
    }
    else if (s==0){
    subbytes.clear();
    int counter=0;
    double oldp,p =0.0;
    for(;c<=bytes.size();c++){
        subbytes.append(bytes[c]);

        if(counter==4000||c==bytes.size()){

            lastChecksum = qChecksum(subbytes.data(), subbytes.length());
            checksumString = "@@@checksum@@@/"+QString::number(lastChecksum)+"/";
            checksumBuffer = checksumString.toUtf8();
            udpSocket->writeDatagram(checksumBuffer,QHostAddress(peerRemoteIP),peerRemotePort);
            qDebug() <<"lastChecksum" <<lastChecksum;

            qDebug() <<"subfile" << c;

            checksumString = "@@@subfile@@@/"+QString::number(c)+"/";
            checksumBuffer = checksumString.toUtf8();
            udpSocket->writeDatagram(checksumBuffer,QHostAddress(peerRemoteIP),peerRemotePort);
            udpSocket->writeDatagram(subbytes, QHostAddress(peerRemoteIP), peerRemotePort);


            p = (double)c/bytes.size();
            p=p*100;
            qDebug()<<(int)(p*100);
           if((int)p>(int)oldp){
               ui->progressBar->setValue(((int)(p)));
               ui->statusLineEdit->setText("Sending progress: "+QString::number((int)(p)));
               oldp=p;
           }
           counter=0;
        }

        counter++;
    }


    }

}
void Client::listenfile(QString fname,int fsize) {
    //qDebug()<<fsize<<"fsize";
    Sleeper::sleep(1);
    data.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(data.data(),data.size(),&peerRemoteIP,&peerRemotePort);
    qDebug()<<"data"<<data;
    quint16 k = qChecksum(data.data(), data.length());
    while(recCS){
        recCS = false;
        if(ACK_OR_NAK(k,recChecksum)){
            fileRec.append(data);
            qDebug()<<data;
            data.clear();
        }
    }


}

void Client::finishRecivingAndSave(){
    QFile file(QFileDialog::getSaveFileName(NULL, tr("Save file"), tr(filename.toLatin1())));
    file.open(QIODevice::Append);
    file.write(fileRec);
}

bool Client::ACK_OR_NAK(quint16 checksum1,quint16 checksum2){
    if(checksum1 == checksum2){
        qDebug()<<"ACK!!!!!!!!!\n";
        QString q = "@@@ACK@@@/";
        QByteArray bufferSent = q.toUtf8();
        udpSocket->writeDatagram(bufferSent, QHostAddress(senderAddress), senderPort);
        return true;
        //sendSub(0);
    }
    else{
        qDebug()<<"NAK!!!!!!!!!!\n";
        QString q = "@@@NAK@@@/";
        QByteArray bufferSent = q.toUtf8();
        udpSocket->writeDatagram(bufferSent, QHostAddress(senderAddress), senderPort);
        return false;
        //sendSub(1);

    }
}

void Client::on_loginPushButton_clicked()
{

    this->username = ui->usernameLineEdit->text();

    this->peerIP = QHostAddress(ui->localIPLineEdit->text());

    QString peerPortString = ui->localPortLineEdit->text();
    this->peerPort = peerPortString.toUShort();


    serverIP = QHostAddress(ui->serverIPLineEdit->text());

    QString serverPortString = ui->serverPortLineEdit->text();
    this->serverPort = serverPortString.toUShort();

    QString error;

    if(this->udpSocket->bind(this->peerIP,this->peerPort))
    {
        this->clientSocket->connectToHost(this->serverIP,this->serverPort);

        if(!clientSocket->waitForConnected(3000))
        {

            QDebug(&error) << this->clientSocket->error();

            QMessageBox::critical(this,"Error!",error);
            this->udpSocket->close();
        }

    }
    else
    {
        QDebug(&error) << this->udpSocket->error();

        QMessageBox::critical(this,"Error!",error);
    }

}

void Client::on_interfacesComboBox_currentIndexChanged(int index)
{
    if(this->interfacesIPsQListInitialized)
    {
        this->peerIP = this->interfacesIPs.at(index);
    }
    else
    {
        this->peerIP=QHostAddress::LocalHost;
    }

    ui->localIPLineEdit->setText(this->peerIP.toString());

}

void Client::connected()
{

    QByteArray clientInformation;
    clientInformation.append(this->username);
    clientInformation.append(",");
    clientInformation.append(this->peerIP.toString());
    clientInformation.append(",");
    clientInformation.append(QString::number(this->peerPort));
    clientInformation.append(",");


    this->clientSocket->write(clientInformation);

    if(!this->clientSocket->waitForBytesWritten(3000))
    {
        QString error = this->udpSocket->errorString();

        QMessageBox::critical(this,"Error!",error);
    }

}

void Client::disconnected()
{
    this->clientSocket->close();
    this->udpSocket->close();

    this->clientsUsernamesOnlineQList.clear();
    this->clientsAddressesOnlineQList.clear();
    this->clientsPortsOnlineQList.clear();

    ui->remoteIPLineEdit->setText("");
    ui->remotePortLineEdit->setText("");
    ui->statusLineEdit->setText("");

    ui->onlineUsersListWidget->clear();

}

void Client::readyReadQTcpSocket()
{
      QByteArray clientsUsersOnlineQByteArray = QByteArray(this->clientSocket->readAll());

      QString clientsUsersOnlineQString = QString(clientsUsersOnlineQByteArray);
      QStringList clientsUsersOnlineQStringList = clientsUsersOnlineQString.split(',');

      clientsUsersOnlineQStringList.removeLast();

    // <Client which sent the signal is a new client>
      if( clientsUsersOnlineQStringList[0].compare("All") == 0 )
      {
          clientsUsersOnlineQStringList.removeAt(0);

          for(int i=0;i<clientsUsersOnlineQStringList.length();i+=3)
          {

              this->clientsUsernamesOnlineQList.append(clientsUsersOnlineQStringList[i]);
              ui->onlineUsersListWidget->addItem(clientsUsersOnlineQStringList[i]);

              this->clientsAddressesOnlineQList.append(QHostAddress(clientsUsersOnlineQStringList[i+1]));
              this->clientsPortsOnlineQList.append(clientsUsersOnlineQStringList[i+2].toUShort());


          }
      }
      // </Client which sent the signal is a new client>

      // <Client which sent the signal is not a new client and there is an add client event>
      else if(clientsUsersOnlineQStringList[0].compare("Add") == 0)
      {

          this->clientsUsernamesOnlineQList.append(clientsUsersOnlineQStringList[1]);
          ui->onlineUsersListWidget->addItem(clientsUsersOnlineQStringList[1]);

          this->clientsAddressesOnlineQList.append(QHostAddress(clientsUsersOnlineQStringList[2]));
          this->clientsPortsOnlineQList.append(clientsUsersOnlineQStringList[3].toUShort());

      }
      // </Client which sent the signal is not a new client and there is an add client event>

      // <Client which sent the signal is not a new client and there is a remove client event>
      else if(clientsUsersOnlineQStringList[0].compare("Remove") == 0)
      {
          int index = clientsUsersOnlineQStringList[1].toInt();

          this->clientsUsernamesOnlineQList.removeAt(index);
          this->clientsAddressesOnlineQList.removeAt(index);
          this->clientsPortsOnlineQList.removeAt(index);


          QListWidgetItem* item = ui->onlineUsersListWidget->takeItem(index);
          delete item;

      }
      // </Client which sent the signal is not a new client and there is a remove client event>


}

void Client::on_onlineUsersListWidget_clicked(const QModelIndex &index)
{
   this->peerRemoteIP = this->clientsAddressesOnlineQList.at(index.row());
   this->peerRemotePort = this->clientsPortsOnlineQList.at(index.row());

   ui->remoteIPLineEdit->setText(this->peerRemoteIP.toString());
   ui->remotePortLineEdit->setText(QString::number(this->peerRemotePort));

}

void Client::on_logoutPushButton_clicked()
{
    emit disconnected();

}

void Client::on_sendPushButton_clicked()
{
    if(ui->msgLineEdit->text()!=""){

    this->peerRemoteIP = QHostAddress(ui->remoteIPLineEdit->text());
    this->peerRemotePort = ui->remotePortLineEdit->text().toUShort();

    QByteArray bufferSent = ui->msgLineEdit->text().toUtf8();
    this->udpSocket->writeDatagram(bufferSent,this->peerRemoteIP,this->peerRemotePort);
    QString text("<FONT COLOR=red>Me: ");
    text.append(ui->msgLineEdit->text());
    text.append("</FONT>");
    ui->chatTextBrowser->append(text);
    ui->msgLineEdit->setText("");
}

}

void Client::readyReadQUdpSocket()
{

    QByteArray bufferRecieved;
    bufferRecieved.resize(udpSocket->pendingDatagramSize());

    udpSocket->readDatagram(bufferRecieved.data(),bufferRecieved.size(),&senderAddress,&senderPort);
    QString str1=bufferRecieved.data();
    //qDebug()<<bufferRecieved;
    qDebug()<<bufferRecieved.data();

    QStringList myStringListslash = str1.split('/');
    qDebug()<<myStringListslash[0];

    if(myStringListslash[0] == "@@@file@@@"){
        qDebug()<<"file";
        filename=myStringListslash[myStringListslash.size()-1];
        fileSize=myStringListslash[1].toInt();
    }
    else if(myStringListslash[0] == "@@@subfile@@@"){
        listenfile(filename,fileSize);
    }
    else if(myStringListslash[0] == "@@@finished@@@"){
        qDebug() <<"finished";
        finishRecivingAndSave();

    }
    else if(myStringListslash[0] == "@@@checksum@@@"){
         recChecksum = (myStringListslash[1]).toUShort();
         recCS = true;
         qDebug() <<"recivedChecksum" <<recChecksum;
       // ACK_OR_NAK(t);

    }
    else if(myStringListslash[0] == "@@@ACK@@@"){
        qDebug() <<"iii" ;

       ack = true;
       ackRe=true;

    }
    else if(myStringListslash[0] == "@@@NAK@@@"){
        qDebug() <<"ooo" ;

        ack = false;
        ackRe=true;


    }else{
        int index = this->clientsPortsOnlineQList.indexOf(senderPort);

        QString text("<FONT COLOR=blue>");
        text.append(this->clientsUsernamesOnlineQList.at(index) + ": ");

        text.append(bufferRecieved);
        text.append("</FONT>");


        ui->chatTextBrowser->append(text);
        ui->statusLineEdit->setText("Received From IP:" + senderAddress.toString() + ", Port:" + QString::number(senderPort) );
    }
}

void Client ::getInterfaces()
{

    QList<QNetworkInterface> networkInterfaces = QNetworkInterface::allInterfaces();

    bool hasAddressEntry = false;
    QString interfaceName;

    foreach(QNetworkInterface interface,networkInterfaces)
    {

        QList<QNetworkAddressEntry> addressEntry = interface.addressEntries();

        foreach(QNetworkAddressEntry entry,addressEntry)
        {
            if(!hasAddressEntry)
            {
                interfaceName = interface.name();

                hasAddressEntry = true;
                ui->interfacesComboBox->addItem(interfaceName);
            }

            QHostAddress address = entry.ip();

            if( (interfaceName.compare("lo0") == 0 ) ||  (interfaceName.compare("en0") == 0 ) )
            {
                if(address.protocol()==QAbstractSocket::IPv4Protocol)
                {
                    this->interfacesIPs.append(address);

                }
            }
            else
            {
                   this->interfacesIPs.append(address);

            }

        }
            hasAddressEntry = false;

    }

    this->interfacesIPsQListInitialized=true;
}
