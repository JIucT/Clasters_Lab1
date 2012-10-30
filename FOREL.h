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

class Claster        //мн-во всех объектов
{
public:
    Claster(ifstream& file);      
    friend float Euclidean(vector<float> from, vector<float> to, int propnum);
//protected:      uncomment after testing
    int propnum;        
    vector< vector<float> > objects;
    float distance(vector<float> M);
};


class Forel : public Claster
{
public:   
    Forel(ifstream& file) : Claster(file){}
    void standartization();
    vector< vector<float>* > clustering(int R);  //  кластеризация    
};


#endif	/* FOREL_H */

