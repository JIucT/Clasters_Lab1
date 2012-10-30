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
    Forel* b;
    ifstream objects_state("7.txt");
    if (objects_state)
    {
      b = new Forel(objects_state);
    }
    for (int i=0; i<b->objects.size();++i)
    {
        for (int j=0;j<b->propnum; ++j)
        {
            cout<<b->objects[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    cout<<"after standartization"<<endl<<endl<<endl<<endl<<endl<<endl;
    b->standartization();

    for (int i=0; i<b->objects.size();++i)
    {
        for (int j=0;j<b->propnum; ++j)
        {
            cout<<b->objects[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    
}


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
    test();
    
    QApplication app(argc, argv);
    // create and show your widgets here
//    return app.exec();
    return 0;
}
