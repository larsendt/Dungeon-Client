/****************************************************************************
** Meta object code from reading C++ file 'diceroller.h'
**
** Created: Tue Jan 5 11:07:45 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "diceroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diceroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Diceroller[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      27,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Diceroller[] = {
    "Diceroller\0\0roll()\0clear()\0burn_notes()\0"
};

const QMetaObject Diceroller::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Diceroller,
      qt_meta_data_Diceroller, 0 }
};

const QMetaObject *Diceroller::metaObject() const
{
    return &staticMetaObject;
}

void *Diceroller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Diceroller))
        return static_cast<void*>(const_cast< Diceroller*>(this));
    return QWidget::qt_metacast(_clname);
}

int Diceroller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: roll(); break;
        case 1: clear(); break;
        case 2: burn_notes(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
