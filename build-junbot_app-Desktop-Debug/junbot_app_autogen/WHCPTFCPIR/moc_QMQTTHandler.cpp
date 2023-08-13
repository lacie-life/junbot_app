/****************************************************************************
** Meta object code from reading C++ file 'QMQTTHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hdr/Handler/QMQTTHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMQTTHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMqttHandler_t {
    QByteArrayData data[19];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMqttHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMqttHandler_t qt_meta_stringdata_QMqttHandler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QMqttHandler"
QT_MOC_LITERAL(1, 13, 13), // "MQTT_Received"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "msg"
QT_MOC_LITERAL(4, 32, 18), // "mqttMessageChanged"
QT_MOC_LITERAL(5, 51, 16), // "onMQTT_Connected"
QT_MOC_LITERAL(6, 68, 19), // "onMQTT_disconnected"
QT_MOC_LITERAL(7, 88, 15), // "onMQTT_Received"
QT_MOC_LITERAL(8, 104, 7), // "message"
QT_MOC_LITERAL(9, 112, 14), // "QMqttTopicName"
QT_MOC_LITERAL(10, 127, 5), // "topic"
QT_MOC_LITERAL(11, 133, 12), // "mqtt_Publish"
QT_MOC_LITERAL(12, 146, 9), // "RobotNode"
QT_MOC_LITERAL(13, 156, 4), // "node"
QT_MOC_LITERAL(14, 161, 12), // "MQTT_Subcrib"
QT_MOC_LITERAL(15, 174, 3), // "pub"
QT_MOC_LITERAL(16, 178, 14), // "setMqttMessage"
QT_MOC_LITERAL(17, 193, 12), // "QJsonObject&"
QT_MOC_LITERAL(18, 206, 19) // "setCurrentRobotNode"

    },
    "QMqttHandler\0MQTT_Received\0\0msg\0"
    "mqttMessageChanged\0onMQTT_Connected\0"
    "onMQTT_disconnected\0onMQTT_Received\0"
    "message\0QMqttTopicName\0topic\0mqtt_Publish\0"
    "RobotNode\0node\0MQTT_Subcrib\0pub\0"
    "setMqttMessage\0QJsonObject&\0"
    "setCurrentRobotNode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMqttHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       7,    2,   72,    2, 0x0a /* Public */,
      11,    2,   77,    2, 0x0a /* Public */,
      14,    1,   82,    2, 0x0a /* Public */,
      15,    0,   85,    2, 0x0a /* Public */,
      16,    1,   86,    2, 0x0a /* Public */,
      18,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QJsonObject,   13,    8,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    3,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void QMqttHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMqttHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MQTT_Received((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->mqttMessageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onMQTT_Connected(); break;
        case 3: _t->onMQTT_disconnected(); break;
        case 4: _t->onMQTT_Received((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        case 5: _t->mqtt_Publish((*reinterpret_cast< RobotNode(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 6: _t->MQTT_Subcrib((*reinterpret_cast< RobotNode(*)>(_a[1]))); break;
        case 7: _t->pub(); break;
        case 8: _t->setMqttMessage((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->setCurrentRobotNode((*reinterpret_cast< RobotNode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMqttHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttHandler::MQTT_Received)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QMqttHandler::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttHandler::mqttMessageChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QMqttHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QMqttHandler.data,
    qt_meta_data_QMqttHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMqttHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMqttHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMqttHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMqttHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QMqttHandler::MQTT_Received(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QMqttHandler::mqttMessageChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
