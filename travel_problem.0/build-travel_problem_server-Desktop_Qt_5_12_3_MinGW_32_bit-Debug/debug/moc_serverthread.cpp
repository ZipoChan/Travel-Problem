/****************************************************************************
** Meta object code from reading C++ file 'serverthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../travel_problem_server/serverthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serverThread_t {
    QByteArrayData data[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serverThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serverThread_t qt_meta_stringdata_serverThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "serverThread"
QT_MOC_LITERAL(1, 13, 7), // "sendall"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "data"
QT_MOC_LITERAL(4, 27, 9), // "dataReady"
QT_MOC_LITERAL(5, 37, 2), // "ip"
QT_MOC_LITERAL(6, 40, 8), // "sendData"
QT_MOC_LITERAL(7, 49, 8), // "sockDesc"
QT_MOC_LITERAL(8, 58, 13), // "disconnectTCP"
QT_MOC_LITERAL(9, 72, 6), // "sendto"
QT_MOC_LITERAL(10, 79, 12), // "sendDataSlot"
QT_MOC_LITERAL(11, 92, 9), // "sendtoall"
QT_MOC_LITERAL(12, 102, 12), // "recvDataSlot"
QT_MOC_LITERAL(13, 115, 16) // "disconnectToHost"

    },
    "serverThread\0sendall\0\0data\0dataReady\0"
    "ip\0sendData\0sockDesc\0disconnectTCP\0"
    "sendto\0sendDataSlot\0sendtoall\0"
    "recvDataSlot\0disconnectToHost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serverThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    2,   62,    2, 0x06 /* Public */,
       6,    2,   67,    2, 0x06 /* Public */,
       8,    1,   72,    2, 0x06 /* Public */,
       9,    2,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   80,    2, 0x0a /* Public */,
      11,    1,   85,    2, 0x0a /* Public */,
      12,    2,   88,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    5,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    7,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    7,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,    5,    3,
    QMetaType::Void,

       0        // eod
};

void serverThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serverThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendall((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->dataReady((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->sendData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 3: _t->disconnectTCP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendto((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->sendDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 6: _t->sendtoall((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->recvDataSlot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 8: _t->disconnectToHost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (serverThread::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverThread::sendall)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (serverThread::*)(const QString & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverThread::dataReady)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (serverThread::*)(int , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverThread::sendData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (serverThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverThread::disconnectTCP)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (serverThread::*)(const QByteArray & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serverThread::sendto)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serverThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_serverThread.data,
    qt_meta_data_serverThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serverThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serverThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serverThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int serverThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void serverThread::sendall(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void serverThread::dataReady(const QString & _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void serverThread::sendData(int _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void serverThread::disconnectTCP(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void serverThread::sendto(const QByteArray & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
