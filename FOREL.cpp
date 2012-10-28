#include "FOREL.h"
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>


Objects_set::Objects_set(ifstream& file)
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
     //   vector<float>* c = &newobjpropert;
        objects.push_back(newobjpropert);
    }
}


void Objects_set::standartization()
{
    float xj_ = 0, Sj , tmp;
    for (int i = 0; i < objects.size(); ++i)     //по всем объектам
    {
        for (int k = 0; k < propnum; ++k)        //по всем свойствам
        {
            for (int alongobj = 0; alongobj < objects.size(); ++alongobj) 
            {
                xj_ += objects[alongobj][k];  //сумма к-го свойства всех объектов
            }
            xj_ = xj_ / objects.size();
            for (int alongobj = 0; alongobj < objects.size(); ++alongobj)
            {
                tmp += pow( (objects[alongobj][k]), 2);
            }
            Sj = sqrt( (1 / (objects.size()-1)) * tmp );
            objects[i][k] = ( (objects[i][k] - xj_) / Sj );
        }
    }
}