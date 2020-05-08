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
};

void MainWindow::on_pushButton_res_clicked()
{
    double a = ui->lineEdit_a->text().toDouble();
    double b = ui->lineEdit_b->text().toDouble();
    double y, c;
    y = ui->lineEdit_y->text().toDouble();
    if(ui->radioButton_r->isChecked())
    {
       y *= M_PI / 180;
    }
    c = qSqrt((qPow(a, 2) + qPow(b, 2)) - (2 * a * b * qCos(y)));
    ui->lineEdit_c->setText(QString::number(c));
}
