/*
 * File:   main.cpp
 * Author: phoenix
 *
 * Created on October 26, 2012, 7:33 PM
 */

#include <QtGui/QApplication>
#include "FOREL.h"
#include <fstream>


void test()
{
    Forel* b = new Forel("7.txt");    
    for (int i=0; i<b->objects.size();++i)
    {
        for (int j=0;j<b->propnum; ++j)
        {
            cout<<b->objects[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    cout<<"after standartization"<<endl<<endl<<endl<<endl<<endl<<endl;
//    b->standartization();
    vector< Claster* > clasters; 
    clasters = b->clustering(3);
    for (int h=0; h<clasters.size();++h)
    {
        cout<<"Кластер "<<h<<" включает объекты:"<<endl;
        for (int i=0; i<clasters[h]->objects.size();++i)
        {
            for (int j=0;j<clasters[h]->objects[i].size(); ++j)
            {
                cout<<clasters[h]->objects[i][j]<<"  ";
            }
            cout<<endl;
        }
    }  
    
    
}   


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
    test();
   // cout<<num_of_col("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2 (clustering)/11.txt");
    
    QApplication app(argc, argv);
    // create and show your widgets here
//    return app.exec();
    return 0;
}
