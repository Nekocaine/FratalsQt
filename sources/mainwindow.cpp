#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "fractals/sierpinski.h"
#include "fractals/sierpinskichaos.h"
#include "fractals/tapis.h"
#include "fractals/vicsek.h"
#include "fractals/vicsek45.h"
#include "fractals/vonkoch.h"
#include "fractals/vonkochreverse.h"


#include <QFileDialog>


/*
 * Met à jour le bouton avec la nouvelle couleur de fond color,
 * et peut changer la couleur du texte pour avoir un contraste.
 */
void update_color(QPushButton *button, const QColor &color) {
    const QString style("QPushButton { background-color: %1; color: %2; }");
    QString text_color;

    // Si la couleur de fond est claire, le texte sera sombre, et inversement.
    if (color.lightness() > 127) {
        text_color = "black";
    } else {
        text_color = "white";
    }

    button->setStyleSheet(style.arg(color.name(), text_color));
}


/*
 * Construction de l'UI
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Couleurs par défaut et mise à jour des boutons
    color_1 = "#FF3DA5";
    color_2 = "black";

    // Ajout des implémentations
    fractals.append(new Sierpinski);
    fractals.append(new SierpinskiChaos);
    fractals.append(new Tapis);
    fractals.append(new Vicsek);
    fractals.append(new Vicsek45);
    fractals.append(new VonKoch);
    fractals.append(new VonKochReverse);
    foreach(FractalBase* p, fractals) {
        ui->type_cb->addItem(p->name, qVariantFromValue((void*)p));
    }

    // Ajout des tailles
    ui->size_cb->addItem("256x256", QVariant(256));
    ui->size_cb->addItem("512x512", QVariant(512));
    ui->size_cb->addItem("1024x1024", QVariant(1024));
    ui->size_cb->addItem("2048x2048", QVariant(2048));
    ui->size_cb->setCurrentIndex(1); // 512 par défaut

    // Actions des boutons
    connect(ui->actionQuitter, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(ui->add, SIGNAL(pressed()), this, SLOT(draw_fractal()));
    connect(ui->clear, SIGNAL(pressed()), this, SLOT(clear_fractal()));
    connect(ui->save, SIGNAL(pressed()), this, SLOT(save_fractal()));
    // Après le choix de la fractale, on met à jour la liste des itérations.
    connect(ui->type_cb, SIGNAL(currentTextChanged(QString)), this, SLOT(update_iterations()));

    // On met à jour l'UI maintenant que les valeurs par défaut sont définies
    update_color(ui->color1, color_1);
    update_color(ui->color2, color_2);
    update_iterations();
    draw_fractal();
}


/*
 * Suppression de la fenêtre
 */
MainWindow::~MainWindow() {
    delete ui;

    // Suppression des instances de chaque implémentation de fractale
    foreach(FractalBase* p, fractals) {
        delete p;
    }
}


/*
 * Déssin d'une fractale
 */
void MainWindow::draw_fractal() {
    // On récupère les paramètres choisis
    uint size = ui->size_cb->currentData().toUInt();
    FractalBase *fractal = (FractalBase*)ui->type_cb->currentData().value<void*>();

    // On crée une image vide
    QImage img(size, size, QImage::Format_RGB16);

    // Génération de la fractale
    fractal->gen(img, ui->its_cb->currentText(), color_1, color_2);

    // Affichage
    pixmap = QPixmap::fromImage(img);
    ui->img->setPixmap(pixmap);
}


/*
 * Éffacement du déssin
 */
void MainWindow::clear_fractal() {
    ui->img->clear();
}


/*
 * Enregistrement du déssin
 */
void MainWindow::save_fractal() {
    QString selected_filter;
    QString filename = QFileDialog::getSaveFileName(this, "Enregistrer", "./",
                                                    "PNG (*.png);;JPG (*.jpg);;BMP (*.bmp);;Tous les fichiers (*)",
                                                    &selected_filter);
    if (filename.isEmpty()) {
        return;
    }

    // On ajoute .png si besoin
    if (selected_filter == "PNG (*.png)" && !filename.endsWith(".png")) {
        filename.append(".png");
    }
    else if (selected_filter == "JPG (*.jpg)" && !filename.endsWith(".jpg")) {
        filename.append(".jpg");
    }
    else if (selected_filter == "BMP (*.bmp)" && !filename.endsWith(".bmp")) {
        filename.append(".bmp");
    }

    pixmap.save(filename);
}


/*
 * Mise à jour de la liste des itérations
 * À appeller après la sélection d'une fractale
 */
void MainWindow::update_iterations() {
    ui->its_cb->clear();

    FractalBase *fractal = (FractalBase*)ui->type_cb->currentData().value<void*>();
    ui->its_cb->addItems(fractal->iterations);
}


/*
 * Évenements de clic sur les boutons de couleur
 */

void MainWindow::on_color1_clicked() {
    color_1 = QColorDialog::getColor(color_1);
    update_color(ui->color1, color_1);
}

void MainWindow::on_color2_clicked() {
    color_2 = QColorDialog::getColor(color_2);
    update_color(ui->color2, color_2);
}

