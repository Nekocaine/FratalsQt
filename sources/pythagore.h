#ifndef PYTHAGORE_H
#define PYTHAGORE_H
#include <math.h>

#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class Pythagore : public FractalBase
{
public:
    Pythagore();
    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // PYTHAGORE_H
