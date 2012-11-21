#include "FOREL.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>

int num_of_col(char* fname)
{
    ifstream file(fname);
    if (!file)
    {
        cerr<<"Ошибка открытия файла: "<<fname<<endl;
        exit(3);
    }
    else
    {
        int numofcol = 0;
        char* tmp = new char[255];       //first string is taken as example
        file.getline(tmp, 255, '\n');
        file.close();
        int j = strlen(tmp);
        for(int i = 0; i<j-1; ++i)       //counting columns
        {
            while (tmp[i] == ' ')
            {
                ++i;
            }
            ++numofcol;
            while ( (tmp[i] != ' ') && (i<j-1) )
            {
                ++i;
            }
        }
        return numofcol;
    }
}


float Euclidean(vector<float> from, vector<float> to, int propnum) //euclidean distance
{
    float sum = 0;
    for (int i = 0; i < propnum; ++i)
    {
        sum += pow(from[i] - to[i] ,2);
    }
    return sqrt(sum);
}




                              //Claster


void Claster::add(vector<float>& object)  //adding object
{
    this->objects.push_back(object);
}


Claster::Claster(char* fname)
{
    char tmp[15];
    //char length[3];
    propnum = num_of_col(fname);  //number of properties
    ifstream file(fname);
    if(!file)
    {
        cerr<<"Ошибка открытия файла: "<<fname<<endl;
        exit(3);
    }
    vector<float> newobjpropert;
    while ( !file.eof() )
    {
        for (int i=0; i < propnum; ++i)  
        {
            file >> tmp;
            newobjpropert.push_back(atof(tmp));
        }
        objects.push_back(newobjpropert);
        newobjpropert.clear();
    }
    objects.pop_back();      //end of file is shifted by one row
    
    for(int d=0;d<objects.size();++d)
    {
        for(int l=0;l<propnum;++l)
        {
           cout<<objects[d][l]<<"  ";   
        }
        cout<<endl;
    }    
}


Claster::~Claster()
{
    for (int i=0; i<this->objects.size(); ++i)
    {
        this->objects[i].clear();
    }
   // this->objects.clear();
}

void Claster::standartization()
{
    float tmp = 0;
    vector<float> xj_, Sj;
    
//  filling in vector of  mean value for every property of all objects and filling in vector Sj  
    for (int alongpr = 0; alongpr < propnum; ++alongpr)     //looping by properties
    {
        xj_.push_back(0);
        for (int alongobj = 0; alongobj < objects.size(); ++alongobj)  //loop by objects
        {
            xj_[xj_.size() - 1] += objects[alongobj][alongpr];  //sum of к-th property of all objects
        }
        xj_[xj_.size() - 1] = xj_[xj_.size() - 1] / objects.size();


        Sj.push_back(0);
        for (int alongobj = 0; alongobj < objects.size(); ++alongobj)    //sum of square (xij - xj_)^2 proper by all of objects
        {
            tmp += pow( ( objects[alongobj][alongpr] - xj_[xj_.size() - 1] ), 2 );
        }
        Sj[Sj.size() - 1] = sqrt( tmp / (objects.size()-1) );
        tmp = 0;
    }
    //changing of values of matrix
    for (int i = 0; i < objects.size(); ++i)     //by objects
    {
        for (int k = 0; k < propnum; ++k)        //by properties
        {
            objects[i][k] = ( (objects[i][k] - xj_[k]) / Sj[k] );
        }
    }
}

//Claster::Claster()
//{
//}



                                  //Sphere
Sphere::Sphere( vector<float>& center, float R, Forel* claster)//:Claster()
{
    for(int i=0;i<center.size(); ++i)
    {
        this->center.push_back(center[i]);
    }
    //this->center = center;  //adding center to sphere
    this->propnum = claster->propnum;
   // this->objects = claster->objects;
    for (int i =0; i<claster->objects.size(); ++i)   //loop by each of claster object
    {
        if ( ( Euclidean(this->center, claster->objects[i], this->center.size() ) ) <= R) //if distance from
        {                                                        //center to object <= radius, then add object to sphere
            this->add(claster->objects[i]);
        }
    }
}


Sphere::~Sphere()
{
    //this->~Claster();
    //this->center.clear();
}


vector<float> Sphere::count_center()     //counting center of gravity of sphere
{
    vector<float> newcenter; 
    float sum = 0;
    for (int k=0; k<propnum; ++k)  //loop by each property
    {
        for (int i=0; i<objects.size(); ++i)//loop by rows
        {
            sum += objects[i][k];         //summing properties
        }
        newcenter.push_back(sum/objects.size());  //mean value of property
    }
    return newcenter;
}



                                  //Forel




vector< Claster* > Forel::clustering(int R) 
{
    int M;
    vector< Claster*> after_clustering;  //vector of clustering that is got after clustering
    int proper_array_size = this->objects[0].size();
    vector<float> center_prew; 
    vector<float> center_new;
    bool is_same = false;
    vector<vector<float> >::iterator del_vec;     
    float abs_val = 0;
    Sphere* sphere = NULL;
    while (!this->objects.empty())
    {
        M = rand() % this->objects.size();      //center of new sphere
        abs_val = 0;
            if (sphere != NULL)
            {
                delete(sphere);
               // sphere = NULL;
            }
        for(int i = 0; i<this->objects[M].size(); ++i)  //filling in center
        {
            center_prew.push_back(this->objects[M][i]);
        }
        do
        {
            if (sphere != NULL)
            {
                delete(sphere);
               // sphere = NULL;
            }
            sphere = new Sphere::Sphere(sphere, center_prew, R, this);
            center_new = sphere->count_center();            //counting center of made sphere          //center counting error!!!!!!
            for (int g = 0; g<proper_array_size; ++g)
            {
                 abs_val += fabs(center_new[g] - center_prew[g]);
            }
            center_prew = center_new;
            center_new.clear();
        }while (abs_val > 0.01);           
        after_clustering.push_back(sphere);
       //deleting sphere from the input claster;
       for (int i=0; i<sphere->objects.size(); ++i) //by sphere objects
       {
            del_vec = this->objects.begin();   //iterator by this->objects;
            is_same = true;
            for (int j=0;j<this->objects.size(); ++j)  //by claster objects
            {
                for(int u=0;u<this->objects[j].size(); ++u)   //sphere->object[i] =? this->object[i]
                {
                    if (sphere->objects[i][u] != this->objects[j][u])
                    {
                        is_same = false;
                    }
                }
                if (is_same)  //if sphere->object = this->object
                {
                    this->objects.erase(del_vec);                    
                    break;
                }
            }
        }
    }
}
