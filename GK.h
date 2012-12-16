/* 
 * File:   GK.h
 * Author: phoenix
 *
 * Created on December 15, 2012, 11:46 AM
 */

#include "FOREL.h"


using namespace std;

#ifndef GK_H
#define	GK_H

class Gkk
{
public:
    Gkk(char* fname);
    void standartization();
    Claster* claster;
    vector< Claster* > clustering(int clast_num, float E, float Y);
    vector< vector <float> > centers;    
    Claster* get_distances_matrix();
    void countmembership(int clast_num, float E, float Y);        
    Claster* get_membership_matrix();
private:
    vector< vector< float > > V(int l, float Y);
    void set_distances_matrix();
    void set_memberships_byrandom(int numofclusters, int numofobj);
    vector< vector<float> > distance_matrix;           //distences between objects
    vector< vector<float> > membership_matrix;
};


#endif	/* GK_H */

