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
    QByteArrayData data[32];
    char stringdata0[417];
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
QT_MOC_LITERAL(10, 126, 22), // "currentUserNameChanged"
QT_MOC_LITERAL(11, 149, 4), // "user"
QT_MOC_LITERAL(12, 154, 18), // "currentPassChanged"
QT_MOC_LITERAL(13, 173, 4), // "pass"
QT_MOC_LITERAL(14, 178, 18), // "loginStatusChanged"
QT_MOC_LITERAL(15, 197, 6), // "status"
QT_MOC_LITERAL(16, 204, 11), // "LoginStatus"
QT_MOC_LITERAL(17, 216, 18), // "setCurrentScreenID"
QT_MOC_LITERAL(18, 235, 16), // "slotReceiveEvent"
QT_MOC_LITERAL(19, 252, 5), // "event"
QT_MOC_LITERAL(20, 258, 12), // "setRobotMess"
QT_MOC_LITERAL(21, 271, 18), // "setCurrentHostName"
QT_MOC_LITERAL(22, 290, 14), // "setCurrentPort"
QT_MOC_LITERAL(23, 305, 11), // "setUserName"
QT_MOC_LITERAL(24, 317, 7), // "setPass"
QT_MOC_LITERAL(25, 325, 14), // "setLoginStatus"
QT_MOC_LITERAL(26, 340, 17), // "LoginRequestCheck"
QT_MOC_LITERAL(27, 358, 9), // "robotMess"
QT_MOC_LITERAL(28, 368, 15), // "currentHostName"
QT_MOC_LITERAL(29, 384, 11), // "currentPort"
QT_MOC_LITERAL(30, 396, 8), // "userName"
QT_MOC_LITERAL(31, 405, 11) // "loginStatus"

    },
    "AppModel\0currentScreenIDChanged\0\0"
    "currentScreenID\0robotMessChanged\0msg\0"
    "currentHostNameChanged\0hostName\0"
    "currentPortChanged\0port\0currentUserNameChanged\0"
    "user\0currentPassChanged\0pass\0"
    "loginStatusChanged\0status\0LoginStatus\0"
    "setCurrentScreenID\0slotReceiveEvent\0"
    "event\0setRobotMess\0setCurrentHostName\0"
    "setCurrentPort\0setUserName\0setPass\0"
    "setLoginStatus\0LoginRequestCheck\0"
    "robotMess\0currentHostName\0currentPort\0"
    "userName\0loginStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       7,  152, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       6,    1,  105,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
      10,    1,  111,    2, 0x06 /* Public */,
      12,    1,  114,    2, 0x06 /* Public */,
      14,    1,  117,    2, 0x06 /* Public */,
      16,    1,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  123,    2, 0x0a /* Public */,
      18,    1,  126,    2, 0x0a /* Public */,
      20,    1,  129,    2, 0x0a /* Public */,
      21,    1,  132,    2, 0x0a /* Public */,
      22,    1,  135,    2, 0x0a /* Public */,
      23,    1,  138,    2, 0x0a /* Public */,
      24,    1,  141,    2, 0x0a /* Public */,
      25,    1,  144,    2, 0x0a /* Public */,
      26,    2,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   13,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
      27, QMetaType::QString, 0x00495103,
      28, QMetaType::QString, 0x00495103,
      29, QMetaType::QString, 0x00495103,
      30, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      31, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

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
        case 4: _t->currentUserNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->currentPassChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->loginStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->LoginStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setCurrentScreenID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slotReceiveEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setRobotMess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setCurrentHostName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setCurrentPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->setPass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setLoginStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->LoginRequestCheck((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
        {
            using _t = void (AppModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::currentUserNameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::currentPassChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::loginStatusChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (AppModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppModel::LoginStatus)) {
                *result = 7;
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
        case 4: *reinterpret_cast< QString*>(_v) = _t->userName(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->currentPass(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->loginStatus(); break;
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
        case 4: _t->setUserName(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setPass(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setLoginStatus(*reinterpret_cast< bool*>(_v)); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
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

// SIGNAL 4
void AppModel::currentUserNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AppModel::currentPassChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AppModel::loginStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AppModel::LoginStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
