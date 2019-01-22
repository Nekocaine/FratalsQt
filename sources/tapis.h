#ifndef TAPIS_H
#define TAPIS_H

#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class Tapis : public FractalBase
{
public:
    Tapis();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // TAPIS_H
