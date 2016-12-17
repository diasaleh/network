/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[22];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 9), // "connected"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "disconnected"
QT_MOC_LITERAL(4, 31, 19), // "readyReadQTcpSocket"
QT_MOC_LITERAL(5, 51, 19), // "readyReadQUdpSocket"
QT_MOC_LITERAL(6, 71, 26), // "on_loginPushButton_clicked"
QT_MOC_LITERAL(7, 98, 41), // "on_interfacesComboBox_current..."
QT_MOC_LITERAL(8, 140, 5), // "index"
QT_MOC_LITERAL(9, 146, 32), // "on_onlineUsersListWidget_clicked"
QT_MOC_LITERAL(10, 179, 8), // "sendFile"
QT_MOC_LITERAL(11, 188, 27), // "on_logoutPushButton_clicked"
QT_MOC_LITERAL(12, 216, 21), // "on_fileButton_clicked"
QT_MOC_LITERAL(13, 238, 10), // "listenfile"
QT_MOC_LITERAL(14, 249, 5), // "fname"
QT_MOC_LITERAL(15, 255, 5), // "fsize"
QT_MOC_LITERAL(16, 261, 25), // "on_sendPushButton_clicked"
QT_MOC_LITERAL(17, 287, 10), // "ACK_OR_NAK"
QT_MOC_LITERAL(18, 298, 9), // "checksum1"
QT_MOC_LITERAL(19, 308, 9), // "checksum2"
QT_MOC_LITERAL(20, 318, 7), // "sendSub"
QT_MOC_LITERAL(21, 326, 21) // "finishRecivingAndSave"

    },
    "Client\0connected\0\0disconnected\0"
    "readyReadQTcpSocket\0readyReadQUdpSocket\0"
    "on_loginPushButton_clicked\0"
    "on_interfacesComboBox_currentIndexChanged\0"
    "index\0on_onlineUsersListWidget_clicked\0"
    "sendFile\0on_logoutPushButton_clicked\0"
    "on_fileButton_clicked\0listenfile\0fname\0"
    "fsize\0on_sendPushButton_clicked\0"
    "ACK_OR_NAK\0checksum1\0checksum2\0sendSub\0"
    "finishRecivingAndSave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    2,  103,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    2,  109,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      21,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::UShort, QMetaType::UShort,   18,   19,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->readyReadQTcpSocket(); break;
        case 3: _t->readyReadQUdpSocket(); break;
        case 4: _t->on_loginPushButton_clicked(); break;
        case 5: _t->on_interfacesComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_onlineUsersListWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->sendFile(); break;
        case 8: _t->on_logoutPushButton_clicked(); break;
        case 9: _t->on_fileButton_clicked(); break;
        case 10: _t->listenfile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_sendPushButton_clicked(); break;
        case 12: { bool _r = _t->ACK_OR_NAK((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: _t->sendSub((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->finishRecivingAndSave(); break;
        default: ;
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    return QWidget::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
