/* 
 * File:   FOREL.h
 * Author: phoenix
 *
 * Created on October 27, 2012, 10:14 AM
 */

#include <iostream>
#include <vector>

using namespace std;

#ifndef FOREL_H
#define	FOREL_H
/*
class C_Object          //обьект со свойствами
{
public:
    C_Object(vector<float>& propert);
private:
    vector< float > properties;                        
};
*/

class Claster        //мн-во всех объектов
{
protected:
    vector< vector<float> > objects;
};


class Objects_set : Claster
{
public:
    Objects_set(ifstream& file);      //fill in C_object vector while !eof
private:
    int propnum;
public:   
    vector< vector<float>* > clustering(int R);  //  кластеризация
    void standartization();
    
};


#endif	/* FOREL_H */

