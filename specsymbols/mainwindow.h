#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myparserspecsymbols.h"
#include <QMainWindow>
#include <QVector>




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
    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    //MyParserSpecsymbols myParser;
    //void searchOfSpecString();
    bool expressionValidator(QString str, const QString beginValid, const QString endValid);
    QString getResultOfOperation(QString decidStr, const char operation1, const char operation2);
    int myMax(int a, int b, int c, int d);
    int myMin(int a, int b, int c = -1, int d = -1);
    int searchBeginOfExpression(QString &str, int indOperation);
    int searchEndOfExpression(QString &str, int indOperation);
    QString myOperation(QString &str, int indOperation, const QChar operation, int indBeginExp, int indEndExp);
    void permutationOfSpecSymbols(QString str, const QString &begin, const QString &end);
    QString decider(QString strVec);
};

#endif // MAINWINDOW_H
