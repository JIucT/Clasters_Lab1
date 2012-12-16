/*
 * File:   main.cpp
 * Author: phoenix
 *
 * Created on October 26, 2012, 7:33 PM
 */

#include <QtGui/QApplication>
//#include "FOREL.h"
//#include "FOREL2.h"
#include <fstream>
#include <vector>
#include <iomanip>
//#include "Gustafson-Kessel.h"
#include "mainwindow.h"

void test()
{
    Gkk* f = new Gkk("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2(clustering)/8");
 /*   f->set_memberships_byrandom(5, 500);
    for (int i=0; i<f->membership_matrix.size(); ++i)
    {
        for (int j=0; j<f->membership_matrix[i].size(); ++j)
        {
            cout<<f->membership_matrix[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    vector<Claster*> cl;
    f->standartization();
    cl = f->clustering(3, 0.0001, 2);
    for (int i=0; i<cl.size(); ++i)
    {
        cl[i]->show();
        cout<<endl;
    }
}
 
  


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
   // cout<<num_of_col("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2 (clustering)/11.txt");
    srand(static_cast<unsigned>(time(NULL)));
  //  test();

    
    QApplication app(argc, argv);
    
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    // create and show your widgets here
    return app.exec();
//    return 0;
}
