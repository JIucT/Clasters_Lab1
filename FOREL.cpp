#include "FOREL.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>

float Euclidean(vector<float> from, vector<float> to, int propnum) //Эвклидовое расстояние
{
    float sum = 0;
    for (int i = 0; i < propnum; ++i)
    {
        sum += pow(from[i] - to[i] ,2);
    }
    return sqrt(sum);
}



Claster::Claster(ifstream& file)
{
    char tmp[15];
    char length[3];
    file.getline(length, 10000, '\n');        
    propnum = atoi(length);
    vector<float> newobjpropert;
    while (!file.eof())
    {
        for (int i=0; i < propnum; ++i)  
        {
            file >> tmp;
            newobjpropert.push_back(atof(tmp));
        }
        objects.push_back(newobjpropert);
        newobjpropert.clear();
    }
    objects.pop_back();      //конец файла сдвинут на 1-у строку
    
    for(int d=0;d<objects.size();++d)
    {
        for(int l=0;l<propnum;++l)
        {
           cout<<objects[d][l]<<"  ";   
        }
        cout<<endl;
    }    
}


void Forel::standartization()
{
    float tmp = 0;
    vector<float> xj_, Sj;
    
//  заполнение вектора среднего значения для каждого свойства всех объектов и заполнение вектора Sj  
    for (int alongpr = 0; alongpr < propnum; ++alongpr)     //цикл по свойствам
    {
        xj_.push_back(0);
        for (int alongobj = 0; alongobj < objects.size(); ++alongobj)  //цикл по объектам
        {
            xj_[xj_.size() - 1] += objects[alongobj][alongpr];  //сумма к-го свойства всех объектов
        }
        xj_[xj_.size() - 1] = xj_[xj_.size() - 1] / objects.size();


        Sj.push_back(0);
        for (int alongobj = 0; alongobj < objects.size(); ++alongobj)    //сумма квадратов (xij - xj_)^2 св-ва по всем объектам
        {
            tmp += pow( ( objects[alongobj][alongpr] - xj_[xj_.size() - 1] ), 2 );
        }
        Sj[Sj.size() - 1] = sqrt( tmp / (objects.size()-1) );
        tmp = 0;
    }
    //изменение значений матрицы
    for (int i = 0; i < objects.size(); ++i)     //по объектам
    {
        for (int k = 0; k < propnum; ++k)        //по свойствам
        {
            objects[i][k] = ( (objects[i][k] - xj_[k]) / Sj[k] );
        }
    }
}



vector< vector<float>* > Forel::clustering(int R) 
{
    int M;
    M = rand() % this->objects.size();
    
}
