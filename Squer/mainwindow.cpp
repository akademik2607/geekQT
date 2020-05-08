#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_res_clicked()
{
    squareEquation();
}

void MainWindow::squareEquation()
{
    double a = ui->lineEdit_a->text().toInt();
    double b = ui->lineEdit_b->text().toInt();
    double c = ui->lineEdit_c->text().toInt();

    if(a == 0){
        QString message = "Equation is not square.\n";
        double res = (0 - c) / b;
        message = message + "x: " + QString::number(res);
        ui->textEdit_res->setText(message);
    }
    else{
        double d = (b * b) - 4 * a * c;
        if(d < 0){
            ui->textEdit_res->setText("Equation did not have roots.");
        }
        else if(d == 0){
            QString message = "Equation has  alon square.\n";
            double res = -b / (2 * a);
            message = message + "x: " + QString::number(res);
            ui->textEdit_res->setText(message);
        }
        else{
            QString message = "Equation has two roots.\n";
            double res1 = (b + qSqrt(d)) / (2 * a);
            double res2 = (b - qSqrt(d)) / (2 * a);
            message = message + "x1: " + QString::number(res1);
            message = message + "\nx2: " + QString::number(res2);
            ui->textEdit_res->setText(message);

        }
    }

}
