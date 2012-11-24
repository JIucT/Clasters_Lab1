#include "FOREL2.h"
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <math.h>

Forel2::Forel2(char* fname) : Forel(fname)
{
    this->set_distances_matrix();
}

void Forel2::standartization()
{
    this->claster->Claster::standartization();
    this->set_distances_matrix();    
}

void Forel2::set_distances_matrix()
{
    //counting distance between each pair of objects
    vector<float> tmp;
    this->distance_matrix.clear();
    for (int i=0;i<this->claster->objects.size();++i)
    {
        for (int j=0; j<this->claster->objects.size();++j )
        {
            tmp.push_back(Euclidean(this->claster->objects[i], this->claster->objects[j], 
                                                                    this->claster->propnum) );
        }
        this->distance_matrix.push_back(tmp);
        tmp.clear();
    }    
}

//return cluster, whose vetor objects includes distances matrix
Claster* Forel2::get_distances_matrix()
{
    this->distance_matrix.clear();
    this->set_distances_matrix();
    Claster* tmp = new Claster();
    tmp->propnum = this->distance_matrix[0].size();
    tmp->objects = this->distance_matrix;
    return tmp;
}

float Q2(vector< Claster* > claster)
{
    float sum=0;
    for (int k=0; k<claster.size();++k)
    {
        for (int i=0; i<claster[k]->objects.size()-1; ++i)
        {
            for (int h=i+1; h<claster[k]->objects.size(); ++h)
            {
                sum += Euclidean(claster[k]->objects[i], claster[k]->objects[h], claster[k]->propnum);
            }
        }
    }
    return sum;
}



vector< Claster* > Forel2::clustering(int clast_num, float E)
{
    if ( (clast_num <= 0) || (E <= 0) )
    {        
        Claster* err = new Claster();
        err->propnum = 0;        
        vector< Claster* > err_vector;
        err_vector.push_back(err);
        return err_vector;
    }
    float max_dist=0, tmp = 0, R = 0, dR = 0;
    int index = 1;
    Forel* copy_of_claster = new Forel();
  //  this->set_distances_matrix();
    for (int i=0; i<this->distance_matrix.size();++i)       //counting radius for the 1st iteration
    {
        tmp = *max_element(this->distance_matrix[i].begin(), this->distance_matrix[i].end());
        if (max_dist < tmp)
        {
            max_dist = tmp;
        }
    }
    R = max_dist;
    do
    {
        if ( clast_num >= this->forel_result.size() )   //getting new radius
        {
            R = R - dR;
            if (R < 0)
                R = 0;
        }
        else
        {
            R = R + dR;
        }
        this->forel_result.clear();
        *copy_of_claster->claster = *this->claster;     //copying of input data
        this->forel_result = copy_of_claster->Forel::clustering(R);        
        if (clast_num == this->forel_result.size())     //if number of clasters is ok than add this fragmentation	                                                 
        {                                               //to results set
            this->result_set.push_back(this->forel_result);
        }
        else
        {
            for (int i=0; i<this->forel_result.size(); ++i)
            {
                delete(forel_result[i]);
            }

        }
        dR = max_dist/( pow(2, (index - 1) ) );        
        ++index;  //transfer to next iteration
    }while (dR>=E);
    index = 0;
    if (!result_set.empty())
    tmp = Q2(result_set[0]);
    R = 0;
    for (int i=0; i<result_set.size();++i)
    {
        R = Q2(result_set[i]);
        if ( tmp < R )
        {
            tmp = R;
            index = i;
        }
    }
    if (result_set.empty() == false)
        return result_set[index];
    else
    {
        Claster* err = new Claster();
        err->propnum = 0;
        vector<Claster*> T;        
        T.push_back(err);
        return T;
    }
}







