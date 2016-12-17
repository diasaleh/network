#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QWidget>
#include <QList>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

    QList<QHostAddress> interfacesIPs;
    void getInterfaces();

    QTcpServer * serverSocket;
    QList<QTcpSocket *> clientsSockets;

    QHostAddress serverIP;
    quint16 serverPort;

    QList<QString>clientsUsernamesOnlineQList;
    QList<QHostAddress> clientsAddressesOnlineQList;
    QList<quint16> clientsPortsOnlineQList;



public slots:
    void newConnection();
    void disconnected();
    void readyRead();


private slots:
    void on_listeningPushButton_clicked();

private:
    Ui::Server *ui;
    void updateOnlineUsersListWidget();
    QMessageBox msgBox;
    void sendAddOrRemoveSignalToClients(QByteArray clientInformationQByteArray,QTcpSocket * socket);
};

#endif // SERVER_H
