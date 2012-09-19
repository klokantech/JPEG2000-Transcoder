/****************************************************************************
** Meta object code from reading C++ file 'jpeg2000transcoder.h'
**
** Created: Fri 14. Sep 15:15:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../jpeg2000transcoder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jpeg2000transcoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Jpeg2000Transcoder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      38,   19,   19,   19, 0x08,
      67,   19,   19,   19, 0x08,
      79,   19,   19,   19, 0x08,
     106,   99,   19,   19, 0x08,
     151,  129,   19,   19, 0x08,
     184,   19,   19,   19, 0x08,
     199,   19,   19,   19, 0x08,
     222,  213,   19,   19, 0x08,
     257,  251,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Jpeg2000Transcoder[] = {
    "Jpeg2000Transcoder\0\0setOpenFileName()\0"
    "setExistingOutputDirectory()\0transcode()\0"
    "cancelTranscoding()\0folder\0"
    "enableButtons(QString)\0fileName,result,chunk\0"
    "displayProgress(QString,int,int)\0"
    "displayAbout()\0displayHelp()\0fileName\0"
    "overwriteFileDialog(QString)\0index\0"
    "updateProfileDisplay(int)\0"
};

void Jpeg2000Transcoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Jpeg2000Transcoder *_t = static_cast<Jpeg2000Transcoder *>(_o);
        switch (_id) {
        case 0: _t->setOpenFileName(); break;
        case 1: _t->setExistingOutputDirectory(); break;
        case 2: _t->transcode(); break;
        case 3: _t->cancelTranscoding(); break;
        case 4: _t->enableButtons((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->displayProgress((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->displayAbout(); break;
        case 7: _t->displayHelp(); break;
        case 8: _t->overwriteFileDialog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->updateProfileDisplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Jpeg2000Transcoder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Jpeg2000Transcoder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Jpeg2000Transcoder,
      qt_meta_data_Jpeg2000Transcoder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Jpeg2000Transcoder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Jpeg2000Transcoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Jpeg2000Transcoder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Jpeg2000Transcoder))
        return static_cast<void*>(const_cast< Jpeg2000Transcoder*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Jpeg2000Transcoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
