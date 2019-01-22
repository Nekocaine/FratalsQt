#include "vonkoch.h"

#include <math.h>
#include <iostream>

#include <QImage>
#include <QPainter>


VonKoch::VonKoch()
{
    name = "Flocon de Von Koch";   //nom
    //ajout du nombre d'iterations possibles à la liste d'iteration
    iterations.append(" 1 iteration");
    iterations.append(" 2 iterations");
    iterations.append(" 3 iterations");
    iterations.append(" 4 iterations");
    iterations.append(" 5 iterations");
    iterations.append(" 6 iterations");
    iterations.append(" 7 iterations");
    iterations.append(" 8 iterations");
    iterations.append(" 9 iterations");
    iterations.append("10 iterations");
}

//fonction de generation de la fractale
void VonKoch::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iterations.indexOf(its_str) + 1;
    int size = img.size().height();

    img.fill(bg);//couleur de fond

    double cx1 = qCeil(size/5);
    double cy1 = qCeil(size*4/5);
    double cx2 = qCeil(size*4/5);
    double cy2 = qCeil(size*4/5);
    double cx3 = qCeil((cx1-cx2)*cos(M_PI/3)-(cy1-cy2)*sin(M_PI/3)+cx2);
    double cy3 = qCeil((cx1-cx2)*sin(M_PI/3)+(cy1-cy2)*cos(M_PI/3)+cy2);

    //initialisation du painter
    QPainter painter;
    painter.begin(&img);
    painter.setPen(fg);

    //appel de la fonction recursive sur les trois segments
    VonKochBase::itVonKoch(painter, cx1, cy1, cx2, cy2, its);
    VonKochBase::itVonKoch(painter, cx2, cy2, cx3, cy3, its);
    VonKochBase::itVonKoch(painter, cx3, cy3, cx1, cy1, its);


    painter.end();
}



