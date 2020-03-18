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

void MainWindow::on_pushButton_html_clicked()
{
    ui->textEdit_output->setHtml(ui->lineEdit_input->text());
}

void MainWindow::on_pushButton_addPlain_clicked()
{
    ui->plainTextEdit_output->appendPlainText("Этот текст добавляется!");
}

void MainWindow::on_pushButton_chPlain_clicked()
{
    ui->plainTextEdit_output->setPlainText("Этот текст заменяет!");
}
