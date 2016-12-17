#include "server.h"
#include "ui_server.h"
#include <QDebug>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->listeningPushButton->setStyleSheet("QPushButton {color: green;}");

    this->serverSocket = new QTcpServer();

    this->clientsUsernamesOnlineQList = QList<QString>();
    this->clientsAddressesOnlineQList = QList<QHostAddress>();
    this->clientsPortsOnlineQList = QList<quint16>();

    connect(this->serverSocket,SIGNAL(newConnection()),this,SLOT(newConnection()));

    this->getInterfaces();
}

Server::~Server()
{
    delete ui;
}

void Server::on_listeningPushButton_clicked()
{
        QString serverPortString;
        if( ui->PortLineEdit->text() == ""){
             msgBox.setWindowTitle("Error");
             msgBox.setText("Set port number");
             msgBox.show();
        }
        else{
        if(ui->listeningPushButton->text()=="Start Server"){
            this->serverIP = this->interfacesIPs.at(ui->interfacesComboBox->currentIndex());
            serverPortString = ui->PortLineEdit->text();
            QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
            if (!re.exactMatch(serverPortString)){
                msgBox.setWindowTitle("Error");
                msgBox.setText("port number should be number");
                msgBox.show();
                return;

            }
            this->serverPort = serverPortString.toUShort();

            if(this->serverSocket->listen(serverIP,this->serverPort))
            {
                ui->statusLabel->setText("Status: online on address:" + this->serverIP.toString() + " and port:" + serverPortString );
            }
            else
            {
                ui->statusLabel->setText("Status: offline try to use another port#");
            }
            ui->listeningPushButton->setText("Stop Server");
            ui->listeningPushButton->setStyleSheet("QPushButton {color: red;}");

         }
        else
        {
            foreach (QTcpSocket *s, clientsSockets) {
                       s->close();
                   }
               serverSocket->close();
               ui->listeningPushButton->setText("Start Server");
               ui->listeningPushButton->setStyleSheet("QPushButton {color: green;}");
               ui->statusLabel->setText("Status : Server stopped.");
               ui->onlineUsersListWidget->clear();
        }
        }
}

void Server::newConnection()
{

         QTcpSocket *clientSocket = this->serverSocket->nextPendingConnection();

         this->clientsSockets.append(clientSocket);

         connect(clientSocket, SIGNAL(readyRead()),this,SLOT(readyRead()));
         connect(clientSocket, SIGNAL(disconnected()),this,SLOT(disconnected()));

}

void Server::disconnected()
{

    QTcpSocket *socket = static_cast<QTcpSocket*>(sender()); // sender(): returns a pointer to the object that sent the signal

    int index = this->clientsSockets.indexOf(socket);

    QByteArray clientInformationQByteArray;
    clientInformationQByteArray.append("Remove,");
    clientInformationQByteArray.append(QString::number(index));
    clientInformationQByteArray.append(",");

    this->clientsSockets.removeOne(socket);

    this->clientsUsernamesOnlineQList.removeAt(index);
    this->clientsAddressesOnlineQList.removeAt(index);
    this->clientsPortsOnlineQList.removeAt(index);


    QListWidgetItem* item = ui->onlineUsersListWidget->takeItem(index);
    delete item;

    this->sendAddOrRemoveSignalToClients(clientInformationQByteArray,0);


}

void Server::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender()); // sender(): returns a pointer to the object that sent the signal

    QString clientInformationQString = socket->readAll();
    QStringList clientInformationQStringList = clientInformationQString.split(',');

    this->clientsUsernamesOnlineQList.append(clientInformationQStringList[0]);
    this->clientsAddressesOnlineQList.append(QHostAddress(clientInformationQStringList[1]));
    this->clientsPortsOnlineQList.append(clientInformationQStringList[2].toUShort());

    ui->onlineUsersListWidget->addItem(clientInformationQStringList[0]);

    // <Send all online users to new client which sent the signal>

    QByteArray clientsUsersOnlineQByteArray;
    clientsUsersOnlineQByteArray.append("All,");

    for(int i=0;i<this->clientsUsernamesOnlineQList.length();i++)
    {
        clientsUsersOnlineQByteArray.append(this->clientsUsernamesOnlineQList.at(i));
        clientsUsersOnlineQByteArray.append(",");
        clientsUsersOnlineQByteArray.append(this->clientsAddressesOnlineQList.at(i).toString());
        clientsUsersOnlineQByteArray.append(",");
        clientsUsersOnlineQByteArray.append(QString::number(this->clientsPortsOnlineQList.at(i)));
        clientsUsersOnlineQByteArray.append(",");
    }

    socket->write(clientsUsersOnlineQByteArray);

    socket->flush();

    socket->waitForBytesWritten(3000);

    // </Send all online users to new client which sent the signal>


    // <Send the new online user to rest of clients>

    clientsUsersOnlineQByteArray.clear();
    clientsUsersOnlineQByteArray.append("Add,");
    clientsUsersOnlineQByteArray.append(clientInformationQString);

    this->sendAddOrRemoveSignalToClients(clientsUsersOnlineQByteArray,socket);

    // </Send the new online user to rest of clients>

}

void Server::getInterfaces()
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
}

void Server::sendAddOrRemoveSignalToClients(QByteArray clientInformationQByteArray,QTcpSocket * socket)
{
    foreach (QTcpSocket * clientSocket, this->clientsSockets)
    {
        if(clientSocket != socket)
        {
            clientSocket->write(clientInformationQByteArray);

            clientSocket->flush();

            clientSocket->waitForBytesWritten(3000);
        }
    }
}



