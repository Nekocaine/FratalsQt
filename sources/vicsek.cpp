#include "vicsek.h"
//#include "QPainterPath.h"

#include <iostream>

#include <QImage>
#include <QPainter>

Vicsek::Vicsek()
{
    name = "Fractale de Vicsek";   //nom
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
//fonction recursive de division du carre en 9 avec remplissage de la croix.
void it3(QPainter &painter,QBrush &brush, int cx1, int cy1, int cx2, int cy2,int cx3,int cy3,int cx4,int cy4, int its) {

    if (its > 0) {
        // Division de l'axe des X et des Y en 4 pour pouvoir decouper le carre en 9
        int cix1 = cx1;
        int ciy1 = cy1;
        int cix2 = cx1+(cx4-cx1)/3;
        int ciy2 = cy1+(cy4-cy1)/3;
        int cix3 = cx1+2*(cx4-cx1)/3;
        int ciy3 = cy1+2*(cy4-cy1)/3;
        int cix4 = cx2;
        int ciy4 = cy3;
        //appel de la fonction sur tout les carres de la croix
        it3(painter,brush,cix2,ciy1,cix3,ciy1,cix2,ciy2,cix3,ciy2,its-1);
        it3(painter,brush,cix1,ciy2,cix2,ciy2,cix1,ciy3,cix2,ciy3,its-1);
        it3(painter,brush,cix2,ciy2,cix3,ciy2,cix2,ciy3,cix3,ciy3,its-1);
        it3(painter,brush,cix3,ciy2,cix4,ciy2,cix3,ciy3,cix4,ciy3,its-1);
        it3(painter,brush,cix2,ciy3,cix3,ciy3,cix2,ciy4,cix3,ciy4,its-1);

    }

    else {
        //creation d'un masque de peinture sur le carre
        QPolygon polygon;
        polygon << QPoint(cx1, cy1);
        polygon << QPoint(cx2, cy2);
        polygon << QPoint(cx4, cy4);
        polygon << QPoint(cx3, cy3);
        QPainterPath path;
        path.addPolygon(polygon);
        //creation des carres de couleurs
        painter.drawPolygon(polygon);
        painter.fillPath(path,brush);
        return;
    }

}

//fonction de generation de la fractale
void Vicsek::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iterations.indexOf(its_str) + 1;
    int size = img.size().height();

    img.fill(bg); //couleur de fond
    //coordonnees des 4 coins
    int cx1 = 0;
    int cy1 = 0;
    int cx2 = size;
    int cy2 = 0;
    int cx3 = 0;
    int cy3 = size;
    int cx4 = size;
    int cy4 = size;

    //initialisation du painter
    QPainter painter;
    painter.begin(&img);
    painter.setPen(fg);
    //initialisation du brush
    QBrush brush;
    brush.setColor(fg);
    brush.setStyle(Qt::SolidPattern);

    it3(painter,brush,cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4, its);//appel de la fonction recursive


    painter.end();
}
