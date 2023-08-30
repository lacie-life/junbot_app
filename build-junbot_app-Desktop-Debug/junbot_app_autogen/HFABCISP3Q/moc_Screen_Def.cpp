/****************************************************************************
** Meta object code from reading C++ file 'Screen_Def.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hdr/View/Screen_Def.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Screen_Def.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScreenDef_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScreenDef_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScreenDef_t qt_meta_stringdata_ScreenDef = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ScreenDef"
QT_MOC_LITERAL(1, 10, 10), // "QML_FOLDER"
QT_MOC_LITERAL(2, 21, 7), // "QML_APP"
QT_MOC_LITERAL(3, 29, 15), // "QML_MAIN_SCREEN"
QT_MOC_LITERAL(4, 45, 16), // "QML_LOGIN_SCREEN"
QT_MOC_LITERAL(5, 62, 8), // "QML_TEST"
QT_MOC_LITERAL(6, 71, 8), // "QML_HOME"
QT_MOC_LITERAL(7, 80, 10), // "QML_SEARCH"
QT_MOC_LITERAL(8, 91, 7), // "QML_MAP"
QT_MOC_LITERAL(9, 99, 11), // "QML_CONTROL"
QT_MOC_LITERAL(10, 111, 8) // "QML_USER"

    },
    "ScreenDef\0QML_FOLDER\0QML_APP\0"
    "QML_MAIN_SCREEN\0QML_LOGIN_SCREEN\0"
    "QML_TEST\0QML_HOME\0QML_SEARCH\0QML_MAP\0"
    "QML_CONTROL\0QML_USER"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScreenDef[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095401,
       2, QMetaType::QString, 0x00095401,
       3, QMetaType::QString, 0x00095401,
       4, QMetaType::QString, 0x00095401,
       5, QMetaType::QString, 0x00095401,
       6, QMetaType::QString, 0x00095401,
       7, QMetaType::QString, 0x00095401,
       8, QMetaType::QString, 0x00095401,
       9, QMetaType::QString, 0x00095401,
      10, QMetaType::QString, 0x00095401,

       0        // eod
};

void ScreenDef::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScreenDef *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->QML_FOLDER(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->QML_APP(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->QML_MAIN_SCREEN(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->QML_LOGIN_SCREEN(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->QML_TEST(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->QML_HOME(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->QML_SEARCH(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->QML_MAP(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->QML_CONTROL(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->QML_USER(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ScreenDef::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ScreenDef.data,
    qt_meta_data_ScreenDef,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScreenDef::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScreenDef::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenDef.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScreenDef::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
