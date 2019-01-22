#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class Sierpinski : public FractalBase
{
public:
    Sierpinski();
    virtual ~Sierpinski();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // SIERPINSKI_H
