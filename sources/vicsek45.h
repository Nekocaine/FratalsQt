#ifndef VICSEK45_H
#define VICSEK45_H
#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class Vicsek45 : public FractalBase
{
public:
    Vicsek45();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // VICSEK45_H
