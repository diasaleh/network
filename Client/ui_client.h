/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *serverPortLabel;
    QLineEdit *serverPortLineEdit;
    QFrame *line;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QPushButton *loginPushButton;
    QPushButton *logoutPushButton;
    QTextBrowser *chatTextBrowser;
    QLineEdit *msgLineEdit;
    QPushButton *sendPushButton;
    QPushButton *fileButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *interfacesLabel;
    QComboBox *interfacesComboBox;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *localIPLabel;
    QLineEdit *localIPLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *localPortLabel;
    QLineEdit *localPortLineEdit;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *remoteIPLabel;
    QLineEdit *remoteIPLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *remotePortLabel;
    QLineEdit *remotePortLineEdit;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_6;
    QLabel *onlineUsersLabel;
    QListWidget *onlineUsersListWidget;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *statusLabel;
    QLineEdit *statusLineEdit;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(838, 453);
        layoutWidget = new QWidget(Client);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 40, 235, 58));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        serverIPLabel = new QLabel(layoutWidget);
        serverIPLabel->setObjectName(QStringLiteral("serverIPLabel"));

        horizontalLayout_2->addWidget(serverIPLabel);

        serverIPLineEdit = new QLineEdit(layoutWidget);
        serverIPLineEdit->setObjectName(QStringLiteral("serverIPLineEdit"));

        horizontalLayout_2->addWidget(serverIPLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        serverPortLabel = new QLabel(layoutWidget);
        serverPortLabel->setObjectName(QStringLiteral("serverPortLabel"));

        horizontalLayout_3->addWidget(serverPortLabel);

        serverPortLineEdit = new QLineEdit(layoutWidget);
        serverPortLineEdit->setObjectName(QStringLiteral("serverPortLineEdit"));

        horizontalLayout_3->addWidget(serverPortLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line = new QFrame(Client);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(390, 290, 221, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget1 = new QWidget(Client);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 371, 441));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        usernameLabel = new QLabel(layoutWidget1);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        horizontalLayout->addWidget(usernameLabel);

        usernameLineEdit = new QLineEdit(layoutWidget1);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        horizontalLayout->addWidget(usernameLineEdit);

        loginPushButton = new QPushButton(layoutWidget1);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));

        horizontalLayout->addWidget(loginPushButton);

        logoutPushButton = new QPushButton(layoutWidget1);
        logoutPushButton->setObjectName(QStringLiteral("logoutPushButton"));

        horizontalLayout->addWidget(logoutPushButton);


        verticalLayout->addLayout(horizontalLayout);

        chatTextBrowser = new QTextBrowser(layoutWidget1);
        chatTextBrowser->setObjectName(QStringLiteral("chatTextBrowser"));
        chatTextBrowser->setEnabled(true);

        verticalLayout->addWidget(chatTextBrowser);

        msgLineEdit = new QLineEdit(layoutWidget1);
        msgLineEdit->setObjectName(QStringLiteral("msgLineEdit"));

        verticalLayout->addWidget(msgLineEdit);

        sendPushButton = new QPushButton(layoutWidget1);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));

        verticalLayout->addWidget(sendPushButton);

        fileButton = new QPushButton(layoutWidget1);
        fileButton->setObjectName(QStringLiteral("fileButton"));

        verticalLayout->addWidget(fileButton);

        layoutWidget2 = new QWidget(Client);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(390, 120, 231, 49));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        interfacesLabel = new QLabel(layoutWidget2);
        interfacesLabel->setObjectName(QStringLiteral("interfacesLabel"));

        verticalLayout_3->addWidget(interfacesLabel);

        interfacesComboBox = new QComboBox(layoutWidget2);
        interfacesComboBox->setObjectName(QStringLiteral("interfacesComboBox"));

        verticalLayout_3->addWidget(interfacesComboBox);

        layoutWidget3 = new QWidget(Client);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(390, 220, 231, 58));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        localIPLabel = new QLabel(layoutWidget3);
        localIPLabel->setObjectName(QStringLiteral("localIPLabel"));

        horizontalLayout_4->addWidget(localIPLabel);

        localIPLineEdit = new QLineEdit(layoutWidget3);
        localIPLineEdit->setObjectName(QStringLiteral("localIPLineEdit"));

        horizontalLayout_4->addWidget(localIPLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        localPortLabel = new QLabel(layoutWidget3);
        localPortLabel->setObjectName(QStringLiteral("localPortLabel"));

        horizontalLayout_5->addWidget(localPortLabel);

        localPortLineEdit = new QLineEdit(layoutWidget3);
        localPortLineEdit->setObjectName(QStringLiteral("localPortLineEdit"));

        horizontalLayout_5->addWidget(localPortLineEdit);


        verticalLayout_4->addLayout(horizontalLayout_5);

        layoutWidget4 = new QWidget(Client);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(390, 310, 231, 58));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        remoteIPLabel = new QLabel(layoutWidget4);
        remoteIPLabel->setObjectName(QStringLiteral("remoteIPLabel"));

        horizontalLayout_6->addWidget(remoteIPLabel);

        remoteIPLineEdit = new QLineEdit(layoutWidget4);
        remoteIPLineEdit->setObjectName(QStringLiteral("remoteIPLineEdit"));

        horizontalLayout_6->addWidget(remoteIPLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        remotePortLabel = new QLabel(layoutWidget4);
        remotePortLabel->setObjectName(QStringLiteral("remotePortLabel"));

        horizontalLayout_7->addWidget(remotePortLabel);

        remotePortLineEdit = new QLineEdit(layoutWidget4);
        remotePortLineEdit->setObjectName(QStringLiteral("remotePortLineEdit"));

        horizontalLayout_7->addWidget(remotePortLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        layoutWidget5 = new QWidget(Client);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(640, 40, 181, 331));
        verticalLayout_6 = new QVBoxLayout(layoutWidget5);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        onlineUsersLabel = new QLabel(layoutWidget5);
        onlineUsersLabel->setObjectName(QStringLiteral("onlineUsersLabel"));

        verticalLayout_6->addWidget(onlineUsersLabel);

        onlineUsersListWidget = new QListWidget(layoutWidget5);
        onlineUsersListWidget->setObjectName(QStringLiteral("onlineUsersListWidget"));

        verticalLayout_6->addWidget(onlineUsersListWidget);

        layoutWidget6 = new QWidget(Client);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(390, 390, 421, 23));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(layoutWidget6);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));

        horizontalLayout_8->addWidget(statusLabel);

        statusLineEdit = new QLineEdit(layoutWidget6);
        statusLineEdit->setObjectName(QStringLiteral("statusLineEdit"));
        statusLineEdit->setEnabled(false);
        statusLineEdit->setFrame(false);
        statusLineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(statusLineEdit);

        progressBar = new QProgressBar(Client);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(540, 420, 118, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 420, 131, 16));
#ifndef QT_NO_SHORTCUT
        usernameLabel->setBuddy(usernameLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        serverIPLabel->setText(QApplication::translate("Client", "TCP Server IP:    ", 0));
        serverPortLabel->setText(QApplication::translate("Client", "TCP Server Port:", 0));
        usernameLabel->setText(QApplication::translate("Client", "Username:", 0));
        loginPushButton->setText(QApplication::translate("Client", "Login", 0));
        logoutPushButton->setText(QApplication::translate("Client", "Logout", 0));
        sendPushButton->setText(QApplication::translate("Client", "Send", 0));
        fileButton->setText(QApplication::translate("Client", "Select a file to send", 0));
        interfacesLabel->setText(QApplication::translate("Client", "Avaliable Interfaces", 0));
        localIPLabel->setText(QApplication::translate("Client", "Local IP:            ", 0));
        localPortLabel->setText(QApplication::translate("Client", "Local Port:        ", 0));
        remoteIPLabel->setText(QApplication::translate("Client", "Remote IP:        ", 0));
        remotePortLabel->setText(QApplication::translate("Client", "Remote Port:    ", 0));
        onlineUsersLabel->setText(QApplication::translate("Client", "Online Users:", 0));
        statusLabel->setText(QApplication::translate("Client", "Status:", 0));
        label->setText(QApplication::translate("Client", "File sending prgress:", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
