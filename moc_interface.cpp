/****************************************************************************
** Meta object code from reading C++ file 'interface.h'
**
** Created: Sun Jan 10 17:13:15 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Interface[] = {

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
      26,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      62,   10,   10,   10, 0x08,
      85,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Interface[] = {
    "Interface\0\0save_to_file()\0load_from_file()\0"
    "show_info_widget()\0show_contents_widget()\0"
    "show_license()\0"
};

const QMetaObject Interface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Interface,
      qt_meta_data_Interface, 0 }
};

const QMetaObject *Interface::metaObject() const
{
    return &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Interface))
        return static_cast<void*>(const_cast< Interface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: save_to_file(); break;
        case 1: load_from_file(); break;
        case 2: show_info_widget(); break;
        case 3: show_contents_widget(); break;
        case 4: show_license(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
