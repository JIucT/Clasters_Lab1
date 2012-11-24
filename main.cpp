/*
 * File:   main.cpp
 * Author: phoenix
 *
 * Created on October 26, 2012, 7:33 PM
 */

#include <QtGui/QApplication>
#include "FOREL.h"
#include "FOREL2.h"
#include <fstream>
#include <vector>
#include "mainwindow.h"


void test()
{
    Forel2* b = new Forel2("8.txt");    
     b->claster->standartization();
     b->show();
 //   cout<<"after standartization"<<endl<<endl<<endl<<endl<<endl<<endl;
   
    vector< Claster* > clasters; 
    clasters = b->Forel2::clustering(3, 0.1);
    for (int h=0; h<clasters.size();++h)
    {
        cout<<"Кластер "<<h<<" включает объекты:"<<endl;
        clasters[h]->show();
    }  
    
    
}   


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
    //test();
   // cout<<num_of_col("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2 (clustering)/11.txt");
    
    
    QApplication app(argc, argv);
    
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    // create and show your widgets here
    return app.exec();
}
