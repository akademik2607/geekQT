#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QMap>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QIcon>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_Add_leng_clicked();

    void on_checkBox_clicked();

    void on_Del_leng_clicked();

private:
    Ui::MainWindow *ui;
    QList<QStandardItem*> list;
    QStandardItemModel* model;
};

#endif // MAINWINDOW_H
