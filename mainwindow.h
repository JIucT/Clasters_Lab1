/* 
 * File:   mainwindow.h
 * Author: phoenix
 *
 * Created on November 23, 2012, 8:08 AM
 */
#include <Qt/QtGui>
#include "ui_mainwindow.h"
#include "GK.h"
#include "FOREL2.h"
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>


#ifndef MAINWINDOW_H
#define	MAINWINDOW_H




class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT
    public:    
        MainWindow(QWidget* parent = 0);
    private:            
        QString fname;
        Forel2* cluster;
        Forel2* standardized_cluster;
        Gkk* cluster2;
        Gkk* standardized_cluster2;
        vector< Claster* > clustered_data;
        vector< Claster* > clustered_standart_data;
        vector< Claster* > clustered_data2;
        vector< Claster* > clustered_standart_data2;
        
        vector< QwtPlotCurve* >  curves_vector;
        vector< QVector< QPointF >* > points_vector;
        QPen* pen;
        vector< QwtPlotCurve* >  curves_vector2;
        vector< QVector< QPointF >* > points_vector2;
        QPen* pen2;
        
      //  int red;
       // int green;
        //int blue;
        void fill_in_table(QTableWidget* table, Claster* mean_cluster, QString& prefix);
        void replot_by(int numofx, int numofy, vector< Claster* >& data, QwtPlot* p);
        void load_data();        
    private slots:
        void show_mean_values();
        void get_file_name();
        void show_clustering();
        void clustering();
        void loading_data();
        void replot_chart();
        void show_membership();
        void show_centers();
    signals:
        void clustered();   
        void fname_got();
};

#endif	/* MAINWINDOW_H */

