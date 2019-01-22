#ifndef VONKOCHREVERSE_H
#define VONKOCHREVERSE_H

#include "vonkochbase.h"
#include <QtGui>
#include <QtCore>
#include <map>

class VonKochReverse : public VonKochBase
{
public:
    VonKochReverse();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // VONKOCHREVERSE_H
