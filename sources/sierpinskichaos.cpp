#include "sierpinskichaos.h"

#include <math.h>
#include <iostream>


SierpinskiChaos::SierpinskiChaos() {
    name = "Triangle de Sierpinski - Jeu du Chaos";
    iterations.append("  8k iterations");
    iterations.append(" 16k iterations");
    iterations.append(" 32k iterations");
    iterations.append(" 64k iterations");
    iterations.append("128k iterations");
    iterations.append("256k iterations");
    iterations.append("512k iterations");
}

SierpinskiChaos::~SierpinskiChaos() { }

int iteration_count(int id) {
    return pow(2, 3+id) * 1000;
}

void SierpinskiChaos::gen(QImage &img, const QString &its_str, const QColor &fg, const QColor &bg) const {
    int its = iteration_count(iterations.indexOf(its_str));
    int size = img.size().height();

    img.fill(bg);

    // On définit le premier triangle
    Triangle triangle = {
        {size/2, 1},
        {1, size},
        {size, size},
    };

    // On prend un point aléatoire dans le triangle
    // Le centre de l'image carrée sera toujours dans le triangle équilatéral
    // p sera mis à jour à chaque itération
    Point p = {size/2, size/2};

    while (its > 0) {
        its--;

        // On prend un point aléatoire du triangle
        Point random_p = triangle[rand() % 3];

        // p devient le point entre p et random_p
        p.x = (random_p.x + p.x) / 2;
        p.y = (random_p.y + p.y) / 2;

        // On déssine p
        img.setPixel(p.x, p.y, fg.rgb());
    }
}
