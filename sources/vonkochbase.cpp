#include "vonkochbase.h"

VonKochBase::VonKochBase()
{
}

void VonKochBase::itVonKoch(QPainter &painter, double cx1, double cy1, double cx2, double cy2, int its) const {

    if (its > 0) {
        // Recherche des coordonnees des 2 points formant le tier du segment
        double cix1 = qCeil(cx1+(cx2-cx1)/3);
        double ciy1 = qCeil(cy1+(cy2-cy1)/3);
        double cix2 = qCeil(cx1+2*(cx2-cx1)/3);
        double ciy2 = qCeil(cy1+2*(cy2-cy1)/3);
        //recherche des coordonnes du point formant le triangle equilateral
        double csx = qCeil((cix2-cix1)*cos(M_PI/3)-(ciy2-ciy1)*sin(M_PI/3)+cix1);
        double csy = qCeil((cix2-cix1)*sin(M_PI/3)+(ciy2-ciy1)*cos(M_PI/3)+ciy1);
        //appel de la fonction sur les quatres segments crees
        itVonKoch(painter,cx1,cy1,cix1,ciy1,its-1);
        itVonKoch(painter,cix1,ciy1,csx,csy,its-1);
        itVonKoch(painter,csx,csy,cix2,ciy2,its-1);
        itVonKoch(painter,cix2,ciy2,cx2,cy2,its-1);
    }

    else {
        //creation du segment
        painter.drawLine(cx1,cy1,cx2,cy2);
        return;
    }

}
