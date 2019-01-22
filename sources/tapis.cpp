#include "tapis.h"
//#include "QPainterPath.h"
#include <iostream>

#include <QImage>
#include <QPainter>

Tapis::Tapis()
{
    name = "Tapis de Sierpinski";   //nom
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
//fonction recursive de division du carre en 9 avec remplissage du carre central
void it5(QPainter &painter,QBrush &brush, int cx1, int cy1,int cx4,int cy4, int its) {

    if (its > 0) {
        // Division de l'axe des X et des Y en 4 pour pouvoir decouper le carre en 9
        int cix1 = cx1;
        int ciy1 = cy1;
        int cix2 = cx1+(cx4-cx1)/3;
        int ciy2 = cy1+(cy4-cy1)/3;
        int cix3 = cx1+2*(cx4-cx1)/3;
        int ciy3 = cy1+2*(cy4-cy1)/3;
        int cix4 = cx4;
        int ciy4 = cy4;
        //creation d'un masque de peinture sur le carre central
        QPolygon polygon;
        polygon << QPoint(cix2, ciy2);
        polygon << QPoint(cix3, ciy2);
        polygon << QPoint(cix3, ciy3);
        polygon << QPoint(cix2, ciy3);
        QPainterPath path;
        path.addPolygon(polygon);
        //creation des carres de couleurs
        painter.drawPolygon(polygon);
        painter.fillPath(path,brush);
        //appel de la fonction sur tout les carres sauf celui du milieu
        it5(painter,brush,cix1,ciy1,cix2,ciy2,its-1);
        it5(painter,brush,cix3,ciy1,cix4,ciy2,its-1);
        it5(painter,brush,cix2,ciy1,cix3,ciy2,its-1);
        it5(painter,brush,cix1,ciy2,cix2,ciy3,its-1);
        it5(painter,brush,cix1,ciy3,cix2,ciy4,its-1);
        it5(painter,brush,cix3,ciy3,cix4,ciy4,its-1);
        it5(painter,brush,cix3,ciy2,cix4,ciy3,its-1);
        it5(painter,brush,cix2,ciy3,cix3,ciy4,its-1);
    }
    else{
        return;
        }


}

//fonction de generation de la fractale
void Tapis::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iterations.indexOf(its_str) + 1; //calcul du nombre d'iteration : iteration[0] = "1 iteration"
    int size = img.size().height(); //hauteur = largeur

    img.fill(bg); //couleur de fond

    int cx1 = 0; //coin supperieur gauche du carre
    int cy1 = 0;
    int cx4 = size; //coin inf droit du carre
    int cy4 = size;

    //initialisation du painter
    QPainter painter;
    painter.begin(&img);
    painter.setPen(fg);
    //initialisation du brush
    QBrush brush;
    brush.setColor(fg);
    brush.setStyle(Qt::SolidPattern);

    it5(painter,brush,cx1, cy1, cx4, cy4, its); //appel de la fonction recursive


    painter.end();
}
