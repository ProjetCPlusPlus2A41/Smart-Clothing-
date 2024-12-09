/****************************************************************************
** Meta object code from reading C++ file 'pageclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Atelier_Connexion - Copie (2)/pageclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pageclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pageclient_t {
    QByteArrayData data[18];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pageclient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pageclient_t qt_meta_stringdata_pageclient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "pageclient"
QT_MOC_LITERAL(1, 11, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "on_pushButton_12_clicked"
QT_MOC_LITERAL(4, 61, 22), // "on_tableView_activated"
QT_MOC_LITERAL(5, 84, 5), // "index"
QT_MOC_LITERAL(6, 90, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_pushButton_16_clicked"
QT_MOC_LITERAL(8, 140, 24), // "on_pushButton_18_clicked"
QT_MOC_LITERAL(9, 165, 19), // "on_modifier_clicked"
QT_MOC_LITERAL(10, 185, 21), // "on_modifier_2_clicked"
QT_MOC_LITERAL(11, 207, 23), // "on_buttonsearch_clicked"
QT_MOC_LITERAL(12, 231, 21), // "on_buttonpdff_clicked"
QT_MOC_LITERAL(13, 253, 27), // "on_historiqueButton_clicked"
QT_MOC_LITERAL(14, 281, 14), // "navigateToPage"
QT_MOC_LITERAL(15, 296, 9), // "pageIndex"
QT_MOC_LITERAL(16, 306, 15), // "readFromArduino"
QT_MOC_LITERAL(17, 322, 16) // "on_order_clicked"

    },
    "pageclient\0on_pushButton_9_clicked\0\0"
    "on_pushButton_12_clicked\0"
    "on_tableView_activated\0index\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_16_clicked\0"
    "on_pushButton_18_clicked\0on_modifier_clicked\0"
    "on_modifier_2_clicked\0on_buttonsearch_clicked\0"
    "on_buttonpdff_clicked\0on_historiqueButton_clicked\0"
    "navigateToPage\0pageIndex\0readFromArduino\0"
    "on_order_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pageclient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pageclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pageclient *_t = static_cast<pageclient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_9_clicked(); break;
        case 1: _t->on_pushButton_12_clicked(); break;
        case 2: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_13_clicked(); break;
        case 4: _t->on_pushButton_16_clicked(); break;
        case 5: _t->on_pushButton_18_clicked(); break;
        case 6: _t->on_modifier_clicked(); break;
        case 7: _t->on_modifier_2_clicked(); break;
        case 8: _t->on_buttonsearch_clicked(); break;
        case 9: _t->on_buttonpdff_clicked(); break;
        case 10: _t->on_historiqueButton_clicked(); break;
        case 11: _t->navigateToPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->readFromArduino(); break;
        case 13: _t->on_order_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject pageclient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_pageclient.data,
      qt_meta_data_pageclient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *pageclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pageclient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pageclient.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int pageclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
