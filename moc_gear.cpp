/****************************************************************************
** Meta object code from reading C++ file 'gear.h'
**
** Created: Thu Jan 7 13:53:45 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gear.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gear.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gear[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      12,    5,    5,    5, 0x08,
      21,    5,    5,    5, 0x08,
      28,    5,    5,    5, 0x08,
      38,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Gear[] = {
    "Gear\0\0add()\0remove()\0edit()\0move_up()\0"
    "move_down()\0"
};

const QMetaObject Gear::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Gear,
      qt_meta_data_Gear, 0 }
};

const QMetaObject *Gear::metaObject() const
{
    return &staticMetaObject;
}

void *Gear::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gear))
        return static_cast<void*>(const_cast< Gear*>(this));
    return QWidget::qt_metacast(_clname);
}

int Gear::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: add(); break;
        case 1: remove(); break;
        case 2: edit(); break;
        case 3: move_up(); break;
        case 4: move_down(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
