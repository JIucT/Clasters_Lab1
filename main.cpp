/*
 * File:   main.cpp
 * Author: phoenix
 *
 * Created on October 26, 2012, 7:33 PM
 */

#include <QtGui/QApplication>
#include "FOREL.h"
#include <fstream>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    ifstream objects_state("7.txt");
    if (objects_state)
      Objects_set* b = new Objects_set(objects_state);
    
    
    
    
    
    
    
    // create and show your widgets here

    return app.exec();
}
