/****************************************************************************
** Meta object code from reading C++ file 'AppModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hdr/Model/AppModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppModel_t {
    QByteArrayData data[19];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppModel_t qt_meta_stringdata_AppModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppModel"
QT_MOC_LITERAL(1, 9, 22), // "currentScreenIDChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "currentScreenID"
QT_MOC_LITERAL(4, 49, 16), // "robotMessChanged"
QT_MOC_LITERAL(5, 66, 3), // "msg"
QT_MOC_LITERAL(6, 70, 22), // "currentHostNameChanged"
QT_MOC_LITERAL(7, 93, 8), // "hostName"
QT_MOC_LITERAL(8, 102, 18), // "currentPortChanged"
QT_MOC_LITERAL(9, 121, 4), // "port"
QT_MOC_LITERAL(10, 126, 18), // "setCurrentScreenID"
QT_MOC_LITERAL(11, 145, 16), // "slotReceiveEvent"
QT_MOC_LITERAL(12, 162, 5), // "event"
QT_MOC_LITERAL(13, 168, 12), // "setRobotMess"
QT_MOC_LITERAL(14, 181, 18), // "setCurrentHostName"
QT_MOC_LITERAL(15, 200, 14), // "setCurrentPort"
QT_MOC_LITERAL(16, 215, 9), // "robotMess"
QT_MOC_LITERAL(17, 225, 15), // "currentHostName"
QT_MOC_LITERAL(18, 241, 11) // "currentPort"

    },
    "AppModel\0currentScreenIDChanged\0\0"
    "currentScreenID\0robotMessChanged\0msg\0"
    "currentHostNameChanged\0hostName\0"
    "currentPortChanged\0port\0setCurrentScreenID\0"
    "slotReceiveEvent\0event\0setRobotMess\0"
    "setCurrentHostName\0setCurrentPort\0"
    "robotMess\0currentHostName\0currentPort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       4,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      15,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void AppModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentScreenIDChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->robotMessChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->currentHostNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->currentPortChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setCurrentScreenID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotReceiveEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setRobotMess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setCurrentHostName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setCurrentPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::currentScreenIDChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::robotMessChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::currentHostNameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::currentPortChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentScreenID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->robotMess(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->currentHostName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->currentPort(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AppModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentScreenID(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setRobotMess(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCurrentHostName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCurrentPort(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AppModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AppModel.data,
    qt_meta_data_AppModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppModel::currentScreenIDChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppModel::robotMessChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppModel::currentHostNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AppModel::currentPortChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
