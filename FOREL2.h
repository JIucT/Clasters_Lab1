/* 
 * File:   FOREL2.h
 * Author: phoenix
 *
 * Created on November 22, 2012, 2:33 PM
 */
#include "FOREL.h"


using namespace std;


#ifndef FOREL2_H
#define	FOREL2_H

float Q2(vector< Claster* > claster);

class Forel2 : public Forel
{
public:
    Forel2(char* fname);
    vector< Claster* > clustering(int clast_num, float E);
private:
    vector< vector< Claster* > > result_set;    
    vector < vector<float> > distance_matrix;           //distences between objects
    vector< Claster* > forel_result;    
};


#endif	/* FOREL2_H */

