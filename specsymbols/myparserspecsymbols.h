#ifndef MYPARSERSPECSYMBOLS_H
#define MYPARSERSPECSYMBOLS_H

#include "mainwindow.h"
#include <QMap>


class MyParserSpecsymbols
{
private:
QMap <QString, QChar>symbMap;
public:
    MyParserSpecsymbols();
    QVector<QString> parse(QString& str, QVector<int>& begins, QVector<int>& ends);
    int searcher(QString &str, const QString &search, int from);
    QVector<int> searcher(QString &str, const QString &search);
    QString makrPermutation(QString &str, QString &makr, int perBegin, int perEnd);

};

#endif // MYPARSERSPECSYMBOLS_H
