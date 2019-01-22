#ifndef FRACTALBASE_H
#define FRACTALBASE_H

#include <QtCore>
#include <QImage>


// Représente un point 2D très simplement
typedef struct { int x; int y; } Point;

// Représente un triangle composé de 3 points
typedef Point Triangle[3];


/*
 * Classe de base pour les différentes fractales.
 */
class FractalBase
{
public:
    FractalBase();
    virtual ~FractalBase() = 0;

    // Génère la fractale dans img, avec its itérations et les couleurs fg et bg
    virtual void gen(QImage &img, const QString &its, const QColor &fg, const QColor &bg) const = 0;

    // Nom de la fractale affiché
    QString name;

    // Liste des itérations possibles proposées
    QList<QString> iterations;
};

#endif // FRACTALBASE_H
