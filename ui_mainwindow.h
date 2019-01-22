/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QPushButton *save;
    QSpacerItem *verticalSpacer_4;
    QPushButton *clear;
    QPushButton *color2;
    QPushButton *add;
    QComboBox *type_cb;
    QComboBox *its_cb;
    QPushButton *color1;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *img;
    QLabel *label;
    QLabel *label_3;
    QComboBox *size_cb;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(705, 515);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 18, 0, 1, 1);

        save = new QPushButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));

        gridLayout->addWidget(save, 17, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 14, 0, 1, 1);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));

        gridLayout->addWidget(clear, 16, 0, 1, 1);

        color2 = new QPushButton(centralWidget);
        color2->setObjectName(QStringLiteral("color2"));

        gridLayout->addWidget(color2, 13, 0, 1, 1);

        add = new QPushButton(centralWidget);
        add->setObjectName(QStringLiteral("add"));

        gridLayout->addWidget(add, 15, 0, 1, 1);

        type_cb = new QComboBox(centralWidget);
        type_cb->setObjectName(QStringLiteral("type_cb"));

        gridLayout->addWidget(type_cb, 7, 0, 1, 1);

        its_cb = new QComboBox(centralWidget);
        its_cb->setObjectName(QStringLiteral("its_cb"));

        gridLayout->addWidget(its_cb, 10, 0, 1, 1);

        color1 = new QPushButton(centralWidget);
        color1->setObjectName(QStringLiteral("color1"));

        gridLayout->addWidget(color1, 12, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        img = new QLabel(centralWidget);
        img->setObjectName(QStringLiteral("img"));
        img->setBaseSize(QSize(500, 500));
        img->setScaledContents(false);

        gridLayout->addWidget(img, 3, 1, 16, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 9, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        size_cb = new QComboBox(centralWidget);
        size_cb->setObjectName(QStringLiteral("size_cb"));

        gridLayout->addWidget(size_cb, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 705, 19));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        save->setText(QApplication::translate("MainWindow", "Enregistrer", 0));
        clear->setText(QApplication::translate("MainWindow", "Effacer", 0));
        color2->setText(QApplication::translate("MainWindow", "Couleur #2", 0));
        add->setText(QApplication::translate("MainWindow", "Afficher", 0));
        color1->setText(QApplication::translate("MainWindow", "Couleur #1", 0));
        label_2->setText(QApplication::translate("MainWindow", "R\303\251solution:", 0));
        img->setText(QString());
        label->setText(QApplication::translate("MainWindow", "It\303\251rations:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Fractale:", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
