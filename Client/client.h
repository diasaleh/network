#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtCore>
#include <QList>
#include <QtNetwork>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    bool ack = false;
    bool ackRe = false;
    QByteArray checksumBuffer;
    QString checksumString;
    QList<QHostAddress> interfacesIPs;
    void getInterfaces();
    QHostAddress senderAddress;
    quint16 senderPort;
    QByteArray fileRec;
    bool recCS = false;

    QByteArray data;
    QByteArray bytes,subbytes;
    QTcpSocket * clientSocket;
    QUdpSocket * udpSocket;
    QUdpSocket * fudpSocket;
    QString username;
    QString filename;
    int fileSize;
    QHostAddress serverIP;
    quint16 serverPort;
    quint16 lastChecksum;
    quint16 recChecksum;
    QHostAddress peerIP;
    quint16 peerPort;
    int c =0;
    QHostAddress peerRemoteIP;
    quint16 peerRemotePort;

    bool interfacesIPsQListInitialized;

    QList<QString>clientsUsernamesOnlineQList;
    QList<QHostAddress> clientsAddressesOnlineQList;
    QList<quint16> clientsPortsOnlineQList;


public slots:
    void connected();
    void disconnected();
    void readyReadQTcpSocket();
    void readyReadQUdpSocket();

private slots:
    void on_loginPushButton_clicked();

    void on_interfacesComboBox_currentIndexChanged(int index);

    void on_onlineUsersListWidget_clicked(const QModelIndex &index);
    void sendFile();
    void on_logoutPushButton_clicked();
    void on_fileButton_clicked();
    void listenfile(QString fname,int fsize);
    void on_sendPushButton_clicked();
    bool ACK_OR_NAK(quint16 checksum1,quint16 checksum2);
    void sendSub(int );
    void finishRecivingAndSave();

private:
    Ui::Client *ui;
    void clear();
};

#endif // CLIENT_H
