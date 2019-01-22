#include "sierpinski.h"

#include <math.h>
#include <iostream>

#include <QImage>
#include <QPainter>


Sierpinski::Sierpinski() {
    name = "Triangle de Sierpinski";
    iterations.append(" 1 iterations");
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

Sierpinski::~Sierpinski() { }

void it(QPainter &painter, Triangle triangle, int its) {
    its--;

    if (its < 0) {
        // Dessin du triangle exterieur
        QPolygon polygon;
        polygon << QPoint(triangle[0].x, triangle[0].y);
        polygon << QPoint(triangle[1].x, triangle[1].y);
        polygon << QPoint(triangle[2].x, triangle[2].y);

        painter.drawPolygon(polygon);
        return;
    }

    Triangle central = {
        {(triangle[0].x + triangle[1].x) / 2, (triangle[0].y + triangle[1].y) / 2},
        {(triangle[0].x + triangle[2].x) / 2, (triangle[0].y + triangle[2].y) / 2},
        {(triangle[2].x + triangle[1].x) / 2, (triangle[1].y)},
    };

    Triangle t1 = {triangle[0], central[0], central[1]};
    Triangle t2 = {central[0], triangle[1], central[2]};
    Triangle t3 = {central[1], central[2], triangle[2]};

    it(painter, t1, its);
    it(painter, t2, its);
    it(painter, t3, its);
}


void Sierpinski::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iterations.indexOf(its_str) + 1;
    int size = img.size().height();

    img.fill(bg);

    Triangle triangle = {
        {(size-1)/2, 1},
        {1, size-1},
        {size-1, size-1},
    };

    QPainter painter;
    painter.begin(&img);
    painter.setPen(fg);
    it(painter, triangle, its);

    painter.end();
}
