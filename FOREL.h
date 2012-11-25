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


int num_of_col(char* fname);        //number of columns in file
float Euclidean(vector<float> from, vector<float> to, int propnum); //euclidean distance
class Forel;



class Claster        //set of allobjects
{
public:    
    Claster(char* fname);     
    Claster(){this->propnum = 0;};
    void add(vector<float>& object); //adding object to claster
    friend float Euclidean(vector<float> from, vector<float> to, int propnum);
    void standartization();    
    vector<float> count_center();  //count center of claster, return number of central object in the vector
    void show();
    int propnum;        //object's number of properties
    vector< vector<float> > objects;
};




class Forel
{
public:   
    Forel(char* fname);
    Forel();
    ~Forel();
    virtual vector< Claster* > clustering(float R);  
    friend float Euclidean(vector<float> from, vector<float> to, int propnum);
    void show();
    Claster* claster;
};


#endif	/* FOREL_H */

