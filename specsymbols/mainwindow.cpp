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

bool MainWindow::expressionValidator(QString str, const QString beginValid, const QString endValid){

    int beginInd = str.indexOf(beginValid);
    int beginLength = beginValid.length();
    if(beginInd == -1) return false;

    int endInd = str.indexOf(endValid, beginInd + 1);
    int endLength = endValid.length();

    if(endInd == -1) return false;

    QString strValidation = str.mid(beginInd + beginLength, (endInd - beginInd - beginLength));

    if(strValidation.length() == 0) return false;
    int numsCount = 0;
    for(int i = 0; i < strValidation.length();i++){
        if(strValidation[i].isNumber() || strValidation[i] == '(' || strValidation[i] == ')'
                                            || strValidation[i] == '*' || strValidation[i] == '/'
                || strValidation[i] == '+' || strValidation[i] == '-') {}
        else{
                if(strValidation[i] == 'c'){
                    if(strValidation.indexOf("cos") == strValidation.indexOf('c')){
                        i += 2;
                        continue;
                    }
                }
                else if(strValidation[i] == 't'){
                    if(strValidation.indexOf("tan") == strValidation.indexOf('t')){
                        i += 2;
                        continue;
                    }
                }
                else{
                    return false;
             }
        }
        if(strValidation[i].isNumber()) numsCount++;
    }
   if(numsCount > 0) return true;
   else return false;
}

QString MainWindow::getResultOfOperation(QString decidStr, const char operation1, const char operation2){
    int indBeginExp, indEndExp;
    QString tempResultStr;

    while(true){

    int indOp1 = decidStr.indexOf(operation1);
    int indOp2 = decidStr.indexOf(operation2);
    if(indOp1 == -1 && indOp2 == -1) break;    //Проверить конец
        QChar operation;
        int indOperation;

        if(indOp1 == 0 || indOp2 == 0){
            indOp1 = decidStr.indexOf(operation1, 1);
            indOp2 = decidStr.indexOf(operation2, 1);
            indOperation = myMin(indOp1, indOp2);
            operation = decidStr[indOperation];

        }
        else if((indOp1 != -1 && indOp1 < indOp2) || indOp2 == -1){
            indOperation = indOp1;
            operation = operation1;

        }
        else if((indOp2 != -1 && indOp2 < indOp1) || indOp1 == -1){
            indOperation = indOp2;
            operation = operation2;

        }

            indBeginExp = searchBeginOfExpression(decidStr, indOperation);
            if(indBeginExp == -1) return decidStr;
            indEndExp = searchEndOfExpression(decidStr, indOperation);

            tempResultStr = myOperation(decidStr, indOperation, operation, indBeginExp, indEndExp);


    decidStr.replace(indBeginExp, ((indEndExp + 1) - indBeginExp), tempResultStr);


    }
//    ui->lineEdit->setText(decidStr);
    return decidStr;
}

int MainWindow::myMax(int a, int b, int c, int d){
    int max = a > b ? a : b;
    max = max > c ? max : c;
    return max > d ? max : d;
}

int MainWindow::myMin(int a, int b, int c, int d){
   int min = 0;

   int minArr[] = {a, b, c, d};
   if(a != -1) min = a;
   for(int i = 1;i < 4;i++ ){
        if(minArr[i] != -1) {
            if(min == 0) min = minArr[i];
            else min = min < minArr[i] ? min : minArr[i];
        }
   }

   return min;
}

int MainWindow::searchBeginOfExpression(QString &str, int indOperation){

    int indMinus, indPlus, indDiv, indMult, indBegin;
    if(indOperation == 0) return -1;
    indMinus = str.lastIndexOf('-', (indOperation - 1));
    indPlus = str.lastIndexOf('+', (indOperation - 1));
    indDiv = str.lastIndexOf('/', (indOperation - 1));
    indMult = str.lastIndexOf('*', (indOperation - 1));

    if(indMinus != -1 || indPlus != -1 || indDiv != -1 || indMult != -1){
        indBegin = myMax(indMinus, indPlus, indDiv, indMult) + 1;
        if(indBegin == 1 && indMinus == 0) indBegin = 0;

    }
    else{
        indBegin = 0;
    }
    return indBegin;

}

int MainWindow::searchEndOfExpression(QString &str, int indOperation){
    int indMinus, indPlus, indDiv, indMult, indEnd;

    indMinus = str.indexOf('-', (indOperation + 1));
    indPlus = str.indexOf('+', (indOperation + 1));
    indDiv = str.indexOf('/', (indOperation + 1));
    indMult = str.indexOf('*', (indOperation + 1));



    if(indMinus != -1 || indPlus != -1 || indDiv != -1 || indMult != -1){
        indEnd = myMin(indMinus, indPlus, indDiv, indMult) - 1;
    }
    else{
        indEnd = str.length() - 1;
    }

    return indEnd;
}

QString MainWindow::myOperation(QString &str, int indOperation, const QChar operation, int indBeginExp, int indEndExp){
    double num1;
    double num2;
    QString temp;

    temp = str.mid(indBeginExp, (indOperation - indBeginExp));

    num1 = temp.toDouble();
    if(num1 == 0 && temp != "0" ) return "0";
    temp = str.mid(indOperation + 1, (indEndExp - indOperation));

    num2 = temp.toDouble();
    if(num2 == 0 && temp != "0" ) return "0";

    if(operation == '*'){

        return QString::number(num1 * num2);
    }
    else if(operation == '/' && num2 != 0){      //Сделать проверку деления на ноль

        return QString::number(num1 / num2);
    }
    else if(operation == '+'){
        return QString::number(num1 + num2);
    }
    else if(operation == '-'){
        return QString::number(num1 - num2);
    }
}



void MainWindow::permutationOfSpecSymbols(QString str, const QString &begin, const QString &end){
    int indB;
    int indE;

    if(str.isEmpty()) return;
    MyParserSpecsymbols myParser;
    indB = myParser.searcher(str, begin, 0);
    indE = myParser.searcher(str, end, (indB + begin.length()));
    if(indB == -1 || indE == -1) return;
     QString makr = str.mid(indB + 2, indE - indB - 2);
     QString result = myParser.makrPermutation(str, makr, indB, indE);
     ui->plainTextEdit->setPlainText(result);

}


QString MainWindow:: decider(QString makr){

        int indRight;
        int indLeft;
        QString decidStr;


//        while(makr.indexOf('*') != -1 || makr.indexOf('/') != -1 || makr.indexOf('+') != -1 || makr.indexOf('-') != -1){
            if(makr.indexOf('(') != -1){
                indRight = makr.indexOf(')');
                if(indRight != -1){
                    indLeft = makr.lastIndexOf('(', indRight - 1);
                }
                else return makr;
            }
            else{                                                         //ПРОВЕРИТЬ
                indLeft = 0;
                indRight = makr.length() - 1;
            }
                decidStr = makr.mid(indLeft + 1, (indRight - indLeft - 1));
                decidStr = getResultOfOperation(decidStr, '*', '/');
                decidStr = getResultOfOperation(decidStr, '+', '-');   //Переходим, когда посчитали умножение и деление
            ui->lineEdit->setText(decidStr);

        makr.replace(indLeft, (indRight + 1), decidStr);

 return makr;
}

//}

void MainWindow::on_plainTextEdit_textChanged()
{
 QString str = ui->plainTextEdit->toPlainText();
 permutationOfSpecSymbols(str, "#@", "@");


 /*if(expressionValidator(str, "#@", "=")){
     int beginInd = str.indexOf("#@") + 2;
     int endInd = str.indexOf("=", beginInd) - 1;
    QString temp = str.mid(beginInd, endInd + 1);
    decider(temp);
 }*/



}
