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

class C_Object          //обьект со свойствами
{
    C_Object(ifstream* file);
    vector<float> properties;
};

class Claster        //мн-во всех объектов
{
    vector<C_Object> objects;
public:
    void addobject(C_Object* newobj);
};


class Objects_set : Claster
{
private:
    void standartization();
};


#endif	/* FOREL_H */

