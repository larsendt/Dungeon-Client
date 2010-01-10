/****************************************************************************
** Meta object code from reading C++ file 'spells.h'
**
** Created: Sun Jan 10 17:13:19 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spells.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spells.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spells[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_Spells[] = {
    "Spells\0"
};

const QMetaObject Spells::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Spells,
      qt_meta_data_Spells, 0 }
};

const QMetaObject *Spells::metaObject() const
{
    return &staticMetaObject;
}

void *Spells::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spells))
        return static_cast<void*>(const_cast< Spells*>(this));
    return QWidget::qt_metacast(_clname);
}

int Spells::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SpellList[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      17,   10,   10,   10, 0x08,
      26,   10,   10,   10, 0x08,
      36,   10,   10,   10, 0x08,
      48,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SpellList[] = {
    "SpellList\0\0add()\0remove()\0move_up()\0"
    "move_down()\0prepare()\0"
};

const QMetaObject SpellList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SpellList,
      qt_meta_data_SpellList, 0 }
};

const QMetaObject *SpellList::metaObject() const
{
    return &staticMetaObject;
}

void *SpellList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpellList))
        return static_cast<void*>(const_cast< SpellList*>(this));
    return QWidget::qt_metacast(_clname);
}

int SpellList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: add(); break;
        case 1: remove(); break;
        case 2: move_up(); break;
        case 3: move_down(); break;
        case 4: prepare(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
