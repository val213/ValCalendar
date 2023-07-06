/****************************************************************************
** Meta object code from reading C++ file 'calendar_team.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../calendar_team.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar_team.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calendar_team_t {
    const uint offsetsAndSize[24];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_calendar_team_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_calendar_team_t qt_meta_stringdata_calendar_team = {
    {
QT_MOC_LITERAL(0, 13), // "calendar_team"
QT_MOC_LITERAL(14, 10), // "handleDate"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 4), // "date"
QT_MOC_LITERAL(31, 11), // "team_manage"
QT_MOC_LITERAL(43, 16), // "updateDataToFile"
QT_MOC_LITERAL(60, 3), // "row"
QT_MOC_LITERAL(64, 6), // "column"
QT_MOC_LITERAL(71, 7), // "newText"
QT_MOC_LITERAL(79, 25), // "on_deleteRowButtonClicked"
QT_MOC_LITERAL(105, 20), // "finished_cellChanged"
QT_MOC_LITERAL(126, 7) // "colunmn"

    },
    "calendar_team\0handleDate\0\0date\0"
    "team_manage\0updateDataToFile\0row\0"
    "column\0newText\0on_deleteRowButtonClicked\0"
    "finished_cellChanged\0colunmn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendar_team[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    0,   47,    2, 0x0a,    3 /* Public */,
       5,    3,   48,    2, 0x0a,    4 /* Public */,
       9,    0,   55,    2, 0x0a,    8 /* Public */,
      10,    2,   56,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,   11,

       0        // eod
};

void calendar_team::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<calendar_team *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 1: _t->team_manage(); break;
        case 2: _t->updateDataToFile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->on_deleteRowButtonClicked(); break;
        case 4: _t->finished_cellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject calendar_team::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_calendar_team.offsetsAndSize,
    qt_meta_data_calendar_team,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_calendar_team_t
, QtPrivate::TypeAndForceComplete<calendar_team, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDate, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *calendar_team::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendar_team::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_calendar_team.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int calendar_team::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
