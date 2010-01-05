/****************************************************************************
** Meta object code from reading C++ file 'weaponlist.h'
**
** Created: Wed Dec 30 00:55:30 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "weaponlist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weaponlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WeaponList[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WeaponList[] = {
    "WeaponList\0\0newWeapon()\0"
};

const QMetaObject WeaponList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WeaponList,
      qt_meta_data_WeaponList, 0 }
};

const QMetaObject *WeaponList::metaObject() const
{
    return &staticMetaObject;
}

void *WeaponList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WeaponList))
        return static_cast<void*>(const_cast< WeaponList*>(this));
    return QWidget::qt_metacast(_clname);
}

int WeaponList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newWeapon(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
