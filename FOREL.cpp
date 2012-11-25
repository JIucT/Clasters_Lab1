#include "FOREL.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <math.h>
#include "time.h"

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






vector<float> Claster::count_center()     //counting center of gravity of sphere
{
    vector<float> newcenter; 
    float sum = 0;
    for (int k=0; k<this->propnum; ++k)  //loop by each property
    {
        sum = 0;
        for (int i=0; i<this->objects.size(); ++i)//loop by rows
        {
            sum += objects[i][k];         //summing properties
        }
        newcenter.push_back(sum/objects.size());  //mean value of property        
    }
    return newcenter;
}



void Claster::show()
{
    for (int i=0; i<this->objects.size();++i)
    {
        for (int j=0;j<this->propnum; ++j)
        {
            cout<<this->objects[i][j]<<"  ";
        }
        cout<<endl;
    }    
}

                                  //Forel

Forel::Forel()
{
    this->claster = new Claster();
}


Forel::Forel(char* fname)
{
    this->claster = new Claster(fname);
}

Forel::~Forel()
{
    delete(this->claster);
}

vector< Claster* > Forel::clustering(float R) 
{
    int M = rand() % this->claster->objects.size();
    vector< Claster* > after_clustering;  //vector of clustering that will be got after clustering
    Claster* new_claster = NULL, *ptr = NULL;
    vector<float> center_prew;
    vector<float> center_new;
    vector<vector<float> >::iterator del_vec;
    int abs_val = 0;
    bool is_same;
    while (!this->claster->objects.empty())
    {
   /*     if (R == 0)
        {
            for (int i=this->claster->objects.size()-1;i>=0; --i)
            {
                new_claster = new Claster();
                new_claster->add(this->claster->objects[i]);
                after_clustering.push_back(new_claster);
                del_vec = this->claster->objects.end();
                this->claster->objects.erase(del_vec);
            }
            return after_clustering;
        }
     */   center_prew = this->claster->objects[M];
  //      center_prew = this->claster->count_center();
        do
        {
            if(new_claster != NULL)
            {
                delete(new_claster);
                new_claster = NULL;
            }
            new_claster = new Claster();          //new sphere
            new_claster->propnum = this->claster->propnum;
            for(int i=0;i<this->claster->objects.size(); ++i)      //forming a sphere(new claster)
            {
                if ( Euclidean(center_prew, this->claster->objects[i], center_prew.size() ) <= R)  //if distance from center
                {                                         //of a shphere to curent object <= R than add object to new sphere
                    new_claster->add(this->claster->objects[i]);
                }
            }
            center_new = new_claster->count_center();   //counting new center of a shpere
            abs_val = 0;
            for (int i=0;i<center_prew.size();++i)
            {
                abs_val += (int)fabs(center_new[i] - center_prew[i]);  //the difference between new and previous centers
            }
            center_prew = center_new;
    //    }while(abs_val > 0.005);
        }while(abs_val!=0);
        ptr = new Claster();
        *ptr = *new_claster;
        after_clustering.push_back(ptr);       //saving new claster
                              //deleting ready claster from input claster
        for (int k=0; k<new_claster->objects.size(); ++k) //by number of objects
        {
            del_vec = this->claster->objects.begin();            
            for (int i=0; i<this->claster->objects.size(); ++i) //by number of objects
            {
                is_same = true;
                for (int j=0;j<this->claster->objects[i].size();++j)  //by number of properties
                {
                    if (this->claster->objects[i][j] != new_claster->objects[k][j])
                    {
                        is_same = false;
                    }                    
                }
                if (is_same == true)
                {
                    this->claster->objects.erase(del_vec);
                    break;
                }
                ++del_vec;                
            }
        }        //end deleting
        if (!this->claster->objects.empty())
            M = rand() % this->claster->objects.size();   //new center of new claster(sphere)
    }
    return after_clustering;
}


void Forel::show()
{
    this->claster->show();
}