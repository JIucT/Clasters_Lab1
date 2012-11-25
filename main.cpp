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
#include <iomanip>
#include "mainwindow.h"

void test()
{
    Forel2* f = new Forel2("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2(clustering)/1.txt");
    f->Forel2::standartization();
    vector<Claster*> a = f->clustering(2, 0.0001);
    for(int i =0; i<a.size(); ++i)
    {
        for(int j=0;j<a[i]->objects.size();++j)
        {
            for (int k=0;k<a[i]->objects[j].size();++k)
            {
                if(a[i]->propnum == 0)
                {
                    cout<<"errrrrrrrrrrrrorrrrrrrr";
                }
                cout<<setw(8)<<a[i]->objects[j][k]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }
}
 
   


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    
//    test();
   // cout<<num_of_col("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2 (clustering)/11.txt");
    srand(static_cast<unsigned>(time(NULL)));

    
    QApplication app(argc, argv);
    
    MainWindow* mainwindow = new MainWindow();
    mainwindow->show();
    // create and show your widgets here
    return app.exec();
  //  return 0;
}
