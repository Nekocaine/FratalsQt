#ifndef VONKOCHBASE_H
#define VONKOCHBASE_H

#include "fractalbase.h"
#include "math.h"
#include <QtGui>
#include <QtCore>
#include <map>

class VonKochBase : public FractalBase
{
public:
    VonKochBase();

    void itVonKoch(QPainter &painter, double cx1, double cy1, double cx2, double cy2, int its) const;
};

#endif // VONKOCHBASE_H
