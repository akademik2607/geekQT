/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_a;
    QLineEdit *lineEdit_b;
    QLineEdit *lineEdit_c;
    QLabel *label_a;
    QLabel *label_b;
    QLabel *label_c;
    QTextEdit *textEdit_res;
    QPushButton *pushButton_res;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(428, 303);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_a = new QLineEdit(centralWidget);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(50, 20, 113, 25));
        lineEdit_b = new QLineEdit(centralWidget);
        lineEdit_b->setObjectName(QStringLiteral("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(50, 100, 113, 25));
        lineEdit_c = new QLineEdit(centralWidget);
        lineEdit_c->setObjectName(QStringLiteral("lineEdit_c"));
        lineEdit_c->setGeometry(QRect(50, 180, 113, 25));
        label_a = new QLabel(centralWidget);
        label_a->setObjectName(QStringLiteral("label_a"));
        label_a->setGeometry(QRect(10, 20, 21, 16));
        label_b = new QLabel(centralWidget);
        label_b->setObjectName(QStringLiteral("label_b"));
        label_b->setGeometry(QRect(10, 100, 21, 16));
        label_c = new QLabel(centralWidget);
        label_c->setObjectName(QStringLiteral("label_c"));
        label_c->setGeometry(QRect(10, 180, 21, 16));
        textEdit_res = new QTextEdit(centralWidget);
        textEdit_res->setObjectName(QStringLiteral("textEdit_res"));
        textEdit_res->setGeometry(QRect(190, 50, 171, 131));
        pushButton_res = new QPushButton(centralWidget);
        pushButton_res->setObjectName(QStringLiteral("pushButton_res"));
        pushButton_res->setGeometry(QRect(190, 190, 89, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 20, 131, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 428, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_a->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">a<br/></p></body></html>", Q_NULLPTR));
        label_b->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">b<br/></p></body></html>", Q_NULLPTR));
        label_c->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">c<br/></p></body></html>", Q_NULLPTR));
        pushButton_res->setText(QApplication::translate("MainWindow", "\320\240\320\265\321\210\320\270\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ax^2 + bx + c = 0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
