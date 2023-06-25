/****************************************************************************
** Meta object code from reading C++ file 'TODO_team.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TODO_team.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TODO_team.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TODO_team_t {
    const uint offsetsAndSize[6];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TODO_team_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TODO_team_t qt_meta_stringdata_TODO_team = {
    {
QT_MOC_LITERAL(0, 9), // "TODO_team"
QT_MOC_LITERAL(10, 13), // "TODO_add_team"
QT_MOC_LITERAL(24, 0) // ""

    },
    "TODO_team\0TODO_add_team\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TODO_team[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void TODO_team::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TODO_team *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->TODO_add_team(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TODO_team::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TODO_team::TODO_add_team)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject TODO_team::staticMetaObject = { {
    QMetaObject::SuperData::link<TODOwidget::staticMetaObject>(),
    qt_meta_stringdata_TODO_team.offsetsAndSize,
    qt_meta_data_TODO_team,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TODO_team_t
, QtPrivate::TypeAndForceComplete<TODO_team, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *TODO_team::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TODO_team::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TODO_team.stringdata0))
        return static_cast<void*>(this);
    return TODOwidget::qt_metacast(_clname);
}

int TODO_team::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TODOwidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TODO_team::TODO_add_team()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
