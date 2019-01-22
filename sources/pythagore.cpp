#include "pythagore.h"

Pythagore::Pythagore()
{
    name = "Arbre de Pythagore";   //nom
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
void it6(QPainter &painter, int cx1, int cy1,int cx2,int cy2, int its) {
    if (its>0){
        int xmilieu =(cx1+cx2)/2;
        int xsommet = (sqrt(2.0)/2.0)*(cx1-cx2)*cos(M_PI/4)-(sqrt(2)/2)*(cy1-cy2)*sin(M_PI/4)+cx2;
        int ysommet= (sqrt(2.0)/2.0)*(cx2-cx1)*sin(M_PI/4)+(sqrt(2)/2)*(cy2-cy1)*cos(M_PI/4)+cy1;
        painter.drawLine(xsommet,ysommet,cx1,cy1);
        painter.drawLine(xsommet,ysommet,cx2,cy2);
        int x =xsommet-ysommet+cy1;
        int y =ysommet+xsommet-cx1;
        int xx = x-xsommet+cy1;
        int yy = y-ysommet+cy1;
        painter.drawLine(xsommet,ysommet,x,y);
        painter.drawLine(cx1,cy1,xx,yy);
        painter.drawLine(xx,yy,x,y);
        it6(painter,x,y,xx,yy,its-1);



    }
    else{
        return;
}
}

void Pythagore::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iterations.indexOf(its_str) + 1; //calcul du nombre d'iteration : iteration[0] = "1 iteration"
    int size = img.size().height(); //hauteur = largeur

    img.fill(bg); //couleur de fond

    int x1 = size*2/5; //coin supperieur gauche du carre
    int y1 = size*3/5;
    int x2 = size*3/5; //coin inf droit du carre
    int y2 = size*3/5;
    int x3 = size*3/5;
    int y3 = size*2/5;
    int x4 = size*2/5;
    int y4 = size*2/5;


    //initialisation du painter
    QPainter painter;
    painter.begin(&img);
    painter.setPen(fg);
    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(x3,y3,x4,y4);
    painter.drawLine(x4,y4,x1,y1);



    it6(painter,x3, y3, x4, y4, its); //appel de la fonction recursive


    painter.end();
}
