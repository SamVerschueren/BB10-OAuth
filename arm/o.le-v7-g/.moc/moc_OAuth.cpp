/****************************************************************************
** Meta object code from reading C++ file 'OAuth.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/oauth/OAuth.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OAuth.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_oauth__OAuth[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   27,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_oauth__OAuth[] = {
    "oauth::OAuth\0\0authorized()\0token\0"
    "accessTokenRetrieved(QString)\0"
};

void oauth::OAuth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OAuth *_t = static_cast<OAuth *>(_o);
        switch (_id) {
        case 0: _t->authorized(); break;
        case 1: _t->accessTokenRetrieved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData oauth::OAuth::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject oauth::OAuth::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_oauth__OAuth,
      qt_meta_data_oauth__OAuth, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &oauth::OAuth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *oauth::OAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *oauth::OAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_oauth__OAuth))
        return static_cast<void*>(const_cast< OAuth*>(this));
    return QObject::qt_metacast(_clname);
}

int oauth::OAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void oauth::OAuth::authorized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
