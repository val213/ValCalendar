/****************************************************************************
** Meta object code from reading C++ file 'bridge.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../bridge.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_bridge_t {
    const uint offsetsAndSize[18];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_bridge_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_bridge_t qt_meta_stringdata_bridge = {
    {
QT_MOC_LITERAL(0, 6), // "bridge"
QT_MOC_LITERAL(7, 25), // "distanceAndTimeCalculated"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 8), // "duration"
QT_MOC_LITERAL(43, 8), // "distance"
QT_MOC_LITERAL(52, 14), // "setStartAndEnd"
QT_MOC_LITERAL(67, 5), // "start"
QT_MOC_LITERAL(73, 3), // "end"
QT_MOC_LITERAL(77, 24) // "calculateDistanceAndTime"

    },
    "bridge\0distanceAndTimeCalculated\0\0"
    "duration\0distance\0setStartAndEnd\0start\0"
    "end\0calculateDistanceAndTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_bridge[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,   37,    2, 0x0a,    4 /* Public */,
       8,    2,   42,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void bridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bridge *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->distanceAndTimeCalculated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->setStartAndEnd((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->calculateDistanceAndTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (bridge::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&bridge::distanceAndTimeCalculated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject bridge::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_bridge.offsetsAndSize,
    qt_meta_data_bridge,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_bridge_t
, QtPrivate::TypeAndForceComplete<bridge, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *bridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_bridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int bridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void bridge::distanceAndTimeCalculated(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
