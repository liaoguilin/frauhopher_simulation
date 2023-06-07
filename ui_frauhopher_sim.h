/********************************************************************************
** Form generated from reading UI file 'frauhopher_sim.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAUHOPHER_SIM_H
#define UI_FRAUHOPHER_SIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_frauhopher_sim
{
public:
    QWidget *centralwidget;
    QCustomPlot *customPlot;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *frauhopher_sim)
    {
        if (frauhopher_sim->objectName().isEmpty())
            frauhopher_sim->setObjectName(QString::fromUtf8("frauhopher_sim"));
        frauhopher_sim->resize(1301, 668);
        centralwidget = new QWidget(frauhopher_sim);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 0, 771, 611));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(830, 20, 113, 22));
        lineEdit->setMaximumSize(QSize(16777215, 16777212));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(950, 20, 91, 16));
        label->setTextFormat(Qt::PlainText);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1080, 20, 113, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1208, 20, 51, 20));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(830, 80, 113, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(950, 80, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(850, 210, 441, 311));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../\345\261\217\345\271\225\346\210\252\345\233\276png.png")));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1200, 80, 71, 16));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1080, 80, 113, 22));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(970, 150, 69, 22));
        frauhopher_sim->setCentralWidget(centralwidget);
        menubar = new QMenuBar(frauhopher_sim);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1301, 22));
        frauhopher_sim->setMenuBar(menubar);
        statusbar = new QStatusBar(frauhopher_sim);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        frauhopher_sim->setStatusBar(statusbar);

        retranslateUi(frauhopher_sim);

        QMetaObject::connectSlotsByName(frauhopher_sim);
    } // setupUi

    void retranslateUi(QMainWindow *frauhopher_sim)
    {
        frauhopher_sim->setWindowTitle(QCoreApplication::translate("frauhopher_sim", "frauhopher_sim", nullptr));
        lineEdit->setText(QCoreApplication::translate("frauhopher_sim", "589", nullptr));
        label->setText(QCoreApplication::translate("frauhopher_sim", "wavelength nm", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("frauhopher_sim", "0.5", nullptr));
        label_2->setText(QCoreApplication::translate("frauhopher_sim", "a cm", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("frauhopher_sim", "0.5", nullptr));
        label_3->setText(QCoreApplication::translate("frauhopher_sim", "b cm", nullptr));
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("frauhopher_sim", "distance cm", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("frauhopher_sim", "10", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("frauhopher_sim", "\347\237\251\345\275\242\345\255\224", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("frauhopher_sim", "\345\217\214\347\274\235", nullptr));

    } // retranslateUi

};

namespace Ui {
    class frauhopher_sim: public Ui_frauhopher_sim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAUHOPHER_SIM_H
