/****************************************************************************
** Meta object code from reading C++ file 'REG_N_LOGIN.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../REG_N_LOGIN.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'REG_N_LOGIN.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reg_n_login_t {
    const uint offsetsAndSize[16];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_reg_n_login_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_reg_n_login_t qt_meta_stringdata_reg_n_login = {
    {
QT_MOC_LITERAL(0, 11), // "reg_n_login"
QT_MOC_LITERAL(12, 20), // "reg_n_login_accepted"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 20), // "reg_n_login_rejected"
QT_MOC_LITERAL(55, 8), // "checkusr"
QT_MOC_LITERAL(64, 6), // "USR_ID"
QT_MOC_LITERAL(71, 8), // "USR_PSWD"
QT_MOC_LITERAL(80, 9) // "save_USER"

    },
    "reg_n_login\0reg_n_login_accepted\0\0"
    "reg_n_login_rejected\0checkusr\0USR_ID\0"
    "USR_PSWD\0save_USER"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reg_n_login[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    2,   40,    2, 0x0a,    3 /* Public */,
       7,    0,   45,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void,

       0        // eod
};

void reg_n_login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reg_n_login *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reg_n_login_accepted(); break;
        case 1: _t->reg_n_login_rejected(); break;
        case 2: { int _r = _t->checkusr((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->save_USER(); break;
        default: ;
        }
    }
}

const QMetaObject reg_n_login::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_reg_n_login.offsetsAndSize,
    qt_meta_data_reg_n_login,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_reg_n_login_t
, QtPrivate::TypeAndForceComplete<reg_n_login, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *reg_n_login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reg_n_login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reg_n_login.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int reg_n_login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
