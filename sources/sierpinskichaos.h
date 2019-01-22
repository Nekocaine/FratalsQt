#ifndef SIERPINSKICHAOS_H
#define SIERPINSKICHAOS_H

#include "fractalbase.h"

#include <QtGui>
#include <QtCore>
#include <map>

class SierpinskiChaos : public FractalBase
{
public:
    SierpinskiChaos();
    virtual ~SierpinskiChaos();

    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const;
};

#endif // SIERPINSKICHAOS_H
