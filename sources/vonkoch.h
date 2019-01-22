#ifndef VONKOCH_H
#define VONKOCH_H


#include "vonkochbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class VonKoch : public VonKochBase
{
public:
    VonKoch();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // VONKOCH_H
