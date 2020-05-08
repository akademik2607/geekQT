#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        list.append(new QStandardItem(QIcon("./cplusplus.jpg"), "C++"));
        list.append(new QStandardItem(QIcon("./python.jpg"),"Python"));
        list.append(new QStandardItem(QIcon("./java.jpg"),"Java"));
        list.append(new QStandardItem(QIcon("./cSharp.png"),"C#"));
        list.append(new QStandardItem(QIcon("./php.png"),"PHP"));
        list.append(new QStandardItem(QIcon("./javascript.jpg"),"JavaScript"));
   /* QStringListModel* model = new QStringListModel();

    ui->listView->setModel(model);*/
//    QStandardItem*
    model = new QStandardItemModel(this);

    model->appendColumn(list);

    ui->listView->setModel(model);
    ui->listView->setResizeMode(QListView::Adjust);


    ui->listView->setMovement(QListView::Free);




    ui->listView->setIconSize(QSize(20, 20));






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_leng_clicked()
{

    model->appendRow(new QStandardItem(QIcon("./cplusplus.jpg"), "New"));


}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        ui->listView->setViewMode(QListView::IconMode);
    }
    else{
        ui->listView->setViewMode(QListView::ListMode);
    }
}

void MainWindow::on_Del_leng_clicked()
{
    auto itemInd = ui->listView->currentIndex();
    int index = itemInd.row();

    //    list.removeAt(index);
    model->removeRow(index);

