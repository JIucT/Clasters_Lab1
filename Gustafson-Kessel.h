/* 
 * File:   Gustafson-Kessel.h
 * Author: phoenix
 *
 * Created on December 8, 2012, 11:09 AM
 */

#include "FOREL.h"
#include <stdlib.h>
#include <algorithm>
#include "math.h"


#ifndef GUSTAFSON_KESSEL_H
#define	GUSTAFSON_KESSEL_H


float vectorsum(vector<float> vec);


class GK
{
public:
    GK(char* fname);
    void standartization();
    Claster* claster;
    vector< Claster* > clustering(int clast_num, float E, float Y);
    vector< vector <float> > centers;    
//private:
    vector< vector< float > > V(int l, float Y);
    void countmembership(int clast_num, float E, float Y);    
    void set_distances_matrix();
    void set_memberships_byrandom(int numofclusters, int numofobj);
    vector< vector<float> > distance_matrix;           //distences between objects
    vector< vector<float> > membership_matrix;
};

#endif	/* GUSTAFSON_KESSEL_H */

