#include "myparserspecsymbols.h"
#include "mainwindow.h"

MyParserSpecsymbols::MyParserSpecsymbols()
{

    symbMap["COPYR"] = QChar(0xA9);
    symbMap["PROMIL"] = QChar(0x2030);
    symbMap["EUR"] = QChar(0x20AC);
    symbMap["RUB"] = QChar(0x20BD);
}

QVector<int> MyParserSpecsymbols::searcher(QString &str, const QString &search){
    QVector<int>index;
    int ind = -1;
   do{
        if(ind + 1 < str.length()){
           ind = str.indexOf(search, ind + 1);
           if(ind != -1){
               index.append(ind);
           }
       }
   }while(str.length() > (ind + 1) && ind != -1);
   return index;
}

int MyParserSpecsymbols::searcher(QString &str, const QString &search, int from){
    int ind = str.indexOf(search, from);
   return ind;
}

QVector<QString> MyParserSpecsymbols::parse(QString& str, QVector<int>& begins, QVector<int>& ends){
    QVector<QString> values;
    auto begIt = begins.begin();
    auto endIt = ends.begin();
    while(begIt != begins.end() && endIt != ends.end()){
        if(*begIt > *endIt){
            endIt++;
            continue;
        }
        else{
            values.append(str.mid(*begIt + 2, (*endIt) - (*begIt) - 1));
            begIt++;
            endIt++;
        }
    }
    return values;
}

QString MyParserSpecsymbols::makrPermutation(QString &str, QString &makr, int perBegin, int perEnd){
    if(!symbMap.contains(makr)) return str;
    str.replace(perBegin, (perEnd - perBegin + 1), symbMap[makr]);

    return str;
}
