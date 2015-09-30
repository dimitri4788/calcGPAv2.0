/****************************************************************************
** Meta object code from reading C++ file 'calcGPA.h'
**
** Created: Sat Aug 18 18:23:22 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "calcGPA.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcGPA.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_calcGPA[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      16,    8,    8,    8, 0x08,
      27,    8,    8,    8, 0x08,
      38,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_calcGPA[] = {
    "calcGPA\0\0quit()\0display1()\0display2()\0"
    "about()\0"
};

void calcGPA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        calcGPA *_t = static_cast<calcGPA *>(_o);
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->display1(); break;
        case 2: _t->display2(); break;
        case 3: _t->about(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData calcGPA::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject calcGPA::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_calcGPA,
      qt_meta_data_calcGPA, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &calcGPA::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *calcGPA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *calcGPA::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calcGPA))
        return static_cast<void*>(const_cast< calcGPA*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int calcGPA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
