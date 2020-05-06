#include "searches.h"


QVector<int>& searchSharp(QString &str){
    QVector<int>index;
    int ind = -1;
   do{
        if(ind + 1 < str.length()){
           ind = str.indexOf("#@", ind + 1);
           if(ind != -1){
               index.append(ind);
           }
       }
   }while(str.length() > 3 && ind != -1);
   if(!index.isEmpty()){
       ui->lineEdit->setText("#@ - ");
       for(int i = 0; i < index.length(); i++){
       ui->lineEdit->insert(QString::number(index[i]));
       }
    }
   return &index;
}
