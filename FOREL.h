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
class Forel;



class Claster        //set of allobjects
{
public:    
    Claster(char* fname);     
    Claster(){};
    void add(vector<float>& object); //adding object to claster
    friend float Euclidean(vector<float> from, vector<float> to, int propnum);
    void standartization();    
    vector<float> count_center();  //count center of claster, return number of central object in the vector
//protected:      
    int propnum;        //object's number of properties
    vector< vector<float> > objects;
};




class Forel 
{
public:   
    Forel(char* fname);
    ~Forel();
    vector< Claster* > clustering(int R);  
    friend float Euclidean(vector<float> from, vector<float> to, int propnum);
    Claster* claster;
};


#endif	/* FOREL_H */

