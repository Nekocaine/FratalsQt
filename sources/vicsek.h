#ifndef VICSEK_H
#define VICSEK_H

#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class Vicsek : public FractalBase
{
public:
    Vicsek();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // VICSEK_H
