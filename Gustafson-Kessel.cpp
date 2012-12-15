#include "Gustafson-Kessel.h"

void GK::set_distances_matrix()
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


GK::GK(char* fname)
{
    this->claster = new Claster(fname);
}


void GK::standartization()
{
    this->claster->Claster::standartization();
    this->set_distances_matrix();    
}


void GK::set_memberships_byrandom(int numofclusters, int numofobj)
{
    float tmpfloat = 0, sum = 0;
    vector<float> tmpvector;
    srand(static_cast<unsigned>(time(NULL)));
    
    for (int i=0; i<numofobj; ++i)
    {
        sum = 0;
        this->membership_matrix.push_back(tmpvector);
        for (int j=0; j<numofclusters; ++j)
        {
            tmpfloat = (rand() % 100 + 0.99) / 100.0;
            this->membership_matrix[i].push_back(tmpfloat);            
            sum += tmpfloat;
        }
        while ( (sum>1) || (sum<0.9) )     
        {
            sum = (rand() % 100 + 0.99) / 100;
            tmpfloat = (rand() % this->membership_matrix[i].size());             
            this->membership_matrix[i][tmpfloat] = sum;
            sum = 0;
            for (int j=0; j<this->membership_matrix[i].size(); ++j)
            {
                sum += this->membership_matrix[i][j];
            }                        
        }
    }
}


vector<float> difference(vector< float > minuend, vector< float > subtrahend )
{
    vector< float > difference;
    for(int i=0; i<minuend.size(); ++i)
    {
        difference.push_back(minuend[i] - subtrahend[i]);
    }
    return difference;
}

vector< vector< float > > composition(vector <float> col, vector < float > str)
{
    vector< vector < float > > composition;
    vector< float > tmp;
    for (int i=0; i<col.size(); ++i)
    {
        for (int j=0; j<str.size(); ++j)
        {
            tmp.push_back(col[i] * str[j]);
        }
        composition.push_back(tmp);
        tmp.clear();
    }
    return composition;
}

vector< vector< float > > addition(vector< vector< float > > arg1, vector< vector< float > > arg2)
{
    if (arg1.size() == 0)
    {
        return arg2;
    }
    if (arg2.size() == 0)
    {
        return arg1;
    }
    for (int i=0; i< arg1.size(); ++i)
    {
        for (int j=0; j<arg1[i].size(); ++j)
        {
            arg1[i][j] += arg2[i][j];
        }
    }
    return arg1;
}

vector< vector< float > > GK::V(int l, float Y)
{
    vector< vector< float > > V;
    vector< vector< float > > tmp;    
    vector< float > difference_v;
    float sum = 0;
        //counting sum of u

    for (int i=0; i<membership_matrix.size(); ++i) //obj
    {
        sum += pow(membership_matrix[i][l], Y);
    }

    //counting sum of V
    for (int i=0; i<claster->objects.size(); ++i)
    {
        difference_v = difference(claster->objects[i], centers[l]);
        tmp = addition(composition(difference_v, difference_v), tmp );
        for(int k=0; k<tmp.size(); ++k)
        {
            for (int h=0; h<tmp[k].size(); ++h)
            {
                tmp[k][h] *= pow(this->membership_matrix[i][l], Y);
            }
        }
    V = addition(V, tmp);
/*    for (int v=0; v<tmp.size(); ++v)
    {
        tmp[v].clear();
    }
  */  tmp.clear();
    }   
    
    
    //division
        for(int k=0; k<V.size(); ++k)
        {
            for (int h=0; h<V[k].size(); ++h)
            {
                V[k][h] = V[k][h]/sum;
            }
        }
    return V;
}


float distance(vector<float> obj, vector<float> center)
{
    
}


void GK::countmembership(int clast_num, float E, float Y)
{
    float sum , max;   
    vector<float> center;
    vector< vector< float> > prew_matrix;
    this->set_memberships_byrandom(clast_num, this->claster->objects.size());
    do
    {
        //counting centers
        center.clear();            
        centers.clear();
        for (int i=0; i<clast_num; ++i)  //by clusters
        {
            center.resize(claster->propnum, 0) ;
            for (int j=0; j<membership_matrix.size(); ++j) //by objects
            {   
                for(int p=0; p<claster->propnum; ++p)
                {
                    center[p] += ( (pow(membership_matrix[j][i], Y))* claster->objects[j][p] );
                }
            }
            this->centers.push_back(center);           
            center.clear();            
        }              
        
        for (int c=0; c<clast_num; ++c) //clusters
        {
            sum=0;
            for (int i=0; i<membership_matrix.size(); ++i) //obj
            {
                sum += pow(membership_matrix[i][c], Y);
            }
            for (int i=0; i<claster->propnum; ++i)
            {
                centers[c][i] = centers[c][i]/sum;
              //cout<<centers[c][i]<<"  ";
            }
       //     cout<<endl;
        }
      //  cout<<endl;
        
        
       prew_matrix = membership_matrix;
        
       max = 0;
        //recounting membership matrix
        for (int i=0; i<membership_matrix.size(); ++i)
        {
            for (int j=0; j<membership_matrix[i].size(); ++j)
            {
                sum = 0;                
                for (int c=0; c<clast_num; ++c)
                {
                    sum += pow( ( Euclidean(claster->objects[i], centers[j], claster->propnum)/
                            Euclidean(claster->objects[i], centers[c], claster->propnum) ), 2/(Y-1) );
                }
                membership_matrix[i][j] = 1/sum;
                max = fabs(prew_matrix[i][j]-membership_matrix[i][j]);
            }
        }
       
       for (int i=0; i<membership_matrix.size(); ++i)
       {
           for (int j=0; j< membership_matrix[i].size(); ++j)
           {
               cout<<membership_matrix[i][j]<<"  ";
           }
           cout <<endl;
       }
       cout<<endl;
    }
    while(max>=E);
}


vector< Claster* > GK::clustering(int clast_num, float E, float Y)
{
    float max;
    vector< Claster* > clastered;
    Claster* tmpclaster;
    int cnumber;
//    clastered.resize(clast_num, N);
    this->countmembership(clast_num, E, Y);
    for (int i=0; i<clast_num; ++i)
    {
        tmpclaster = new Claster();
        tmpclaster->propnum = claster->propnum;
        clastered.push_back(tmpclaster);
    }
    for (int i=0; i<membership_matrix.size(); ++i)
    {
        max = 0;
        for (int j=0; j<membership_matrix[i].size(); ++j)
        {
            if (max<membership_matrix[i][j])
                max = membership_matrix[i][j];
        }

        for (int j=0; j<membership_matrix[i].size(); ++j)
        {
            if (max == membership_matrix[i][j])
            {
                cnumber = j;
            }
        }
        clastered[cnumber]->add(claster->objects[i]);       
    }
    return clastered;
}
