#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QColor>

#include "fractalbase.h"

namespace Ui {
class MainWindow;
}

/*
 * Fenêtre principale de l'application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    // Actions sur le déssin
    void draw_fractal();
    void clear_fractal();
    void save_fractal();

    // Mise à jour de la liste des itérations en fonction de la fractale
    void update_iterations();

private slots:
    // Evenements lors d'un clic sur les boutons de couleurs
    void on_color1_clicked();
    void on_color2_clicked();

private:
    Ui::MainWindow *ui;
    QColor color_1;
    QColor color_2;
    QList<FractalBase*> fractals;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
