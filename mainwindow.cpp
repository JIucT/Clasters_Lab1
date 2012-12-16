
#include <QtCore/qvector.h>
#include "time.h"
#include "mainwindow.h"


void MainWindow::get_file_name()
{
     QFileDialog d(this);
     d.setFileMode(QFileDialog::ExistingFile);
     d.setNameFilter(tr("Text files ( * )"));
     d.setViewMode(QFileDialog::List);
     d.setDirectory("/home/phoenix/Study_&_books/Clasters/PatRec/data/lab1,2(clustering)/");
     d.setLabelText(QFileDialog::FileName, "Choose a data file");
     if (d.exec())
     {
          QStringList a = d.selectedFiles();
          this->fname = a[0];
     }     

     this->cluster = NULL;
     this->standardized_cluster = NULL;
     this->cluster2 = NULL;
     this->standardized_cluster2 = NULL;
     
     this->load_data();
     emit this->fname_got();     
}

void MainWindow::load_data()
{
     this->cluster = new Forel2( this->fname.toUtf8().data() );    //making cluster from input data
     this->standardized_cluster = new Forel2( this->fname.toUtf8().data() ); //making standardized cluster
     this->standardized_cluster->Forel2::standartization();      

     this->cluster2 = new Gkk( this->fname.toUtf8().data() );    //making cluster from input data
     this->standardized_cluster2 = new Gkk(this->fname.toUtf8().data() ); //making standardized cluster
     this->standardized_cluster2->Gkk::standartization();      

     
     vector<Claster*> tmp_vec;
     vector<Claster*> tmp_vec2;
     tmp_vec.push_back(this->cluster->claster);
   //  this->replot_by(0, 1, tmp_vec, this->qwtPlot);    
     tmp_vec2.push_back(this->cluster2->claster);
     this->replot_by(0, 1, tmp_vec2, this->qwtPlot_2);    
}

void MainWindow::loading_data()
{
   if (this->fname.isEmpty() == false)
   {         
 /*    if (this->cluster != NULL)
     {
         delete(this->cluster);
     }
     if (this->standardized_cluster != NULL)
     {
         delete(this->standardized_cluster);
     }     
   */  
     Forel2* mean_cluster;
     Gkk* mean_cluster2;
     if (this->standartizationheckBox->isChecked() == false)
     {
         mean_cluster = this->cluster;         //showing unstandardized cluster
         mean_cluster2 = this->cluster2;
     }
     else
     {
         mean_cluster = this->standardized_cluster; //else showing standardized cluster
         mean_cluster2 = this->standardized_cluster2; //else showing standardized cluster         
     }
     //showing cluster
     QString tmpstr = "x";
     fill_in_table(this->starttableWidget, mean_cluster->claster, tmpstr);
     fill_in_table(this->starttableWidget_2, mean_cluster2->claster, tmpstr);     
     
     
     
     
     //showing distances matrix
     Claster* tmp;
     Claster* tmp2;
     tmp = mean_cluster->get_distances_matrix();
     tmp2 = mean_cluster2->get_distances_matrix();     
     tmpstr = "";
     fill_in_table(this->distancestableWidget, tmp, tmpstr);
     fill_in_table(this->distancestableWidget_2, tmp2, tmpstr);
     
     for (int i=0; i<tmp->objects.size(); ++i)
     {
         this->distancestableWidget->setColumnWidth(i, 70);
     }

     for (int i=0; i<tmp2->objects.size(); ++i)
     {
         this->distancestableWidget_2->setColumnWidth(i, 70);
     }

     
     this->clustering();
     
   }  
}

void MainWindow::fill_in_table(QTableWidget* table, Claster* mean_cluster, QString& prefix)
{
     QTableWidgetItem *newItem;
     table->setColumnCount(mean_cluster->propnum);
     table->setRowCount(mean_cluster->objects.size());
     
     //creating vertical and horizontal headers

     for (int i=0; i<mean_cluster->objects.size(); ++i)
     {
         newItem = new QTableWidgetItem(QTableWidgetItem::Type);
         newItem->setTextAlignment(Qt::AlignJustify);         
         newItem->setText(QString::number(i+1));
         table->setVerticalHeaderItem(i, newItem);         
     }

     
     
     QString x;
     for (int i=0; i<mean_cluster->propnum; ++i)
     {
         newItem = new QTableWidgetItem(QTableWidgetItem::Type);
         newItem->setTextAlignment(Qt::AlignHCenter);         
         x=(prefix + QString::number(i + 1) );
         newItem->setText( x );
         table->setHorizontalHeaderItem(i, newItem);
         table->setColumnWidth(i,
                 ( (table->width() - table->verticalHeader()->defaultSectionSize() -
                 table->verticalScrollBar()->width() - 6 )/ mean_cluster->propnum  ) );   
     }
     
     //filling in the table
     for (int i=0; i<mean_cluster->propnum; ++i)
     {
         for (int j=0; j<mean_cluster->objects.size(); ++j)
         {
             newItem = new QTableWidgetItem(QTableWidgetItem::Type);
             newItem->setText(QString::number(mean_cluster->objects[j][i]));
             newItem->setTextAlignment(Qt::AlignJustify);
             table->removeCellWidget(j, i);
             table->setItem(j, i, newItem);         
         }
     }    
}

void MainWindow::clustering()
{
    //clustering data
    this->clustered_data = this->cluster->Forel2::clustering(this->clustersnumspinBox->text().QString::toInt(), 0.001);
    this->clustered_standart_data = this->standardized_cluster->
                                     Forel2::clustering(this->clustersnumspinBox->text().QString::toInt(), 0.01);    

    this->clustered_data2 = this->cluster2->Gkk::clustering(this->clustersnumspinBox->text().QString::toInt(), 0.00001, 2);
    this->clustered_standart_data2 = this->standardized_cluster2->
                                     Gkk::clustering(this->clustersnumspinBox->text().QString::toInt(), 0.001, 2);    




    if (this->cluster != NULL)
    {
        delete(this->cluster);
    }
    if (this->standardized_cluster != NULL)
    {
        delete(this->standardized_cluster);
    }
    
    if (this->cluster2 != NULL)
    {
   //     delete(this->cluster2);
    }
    if (this->standardized_cluster2 != NULL)
    {
     //   delete(this->standardized_cluster2);
    }
    
    
    this->cluster = new Forel2( this->fname.toUtf8().data() );    //making cluster from input data
    this->standardized_cluster = new Forel2( this->fname.toUtf8().data() ); //making standardized cluster
    this->standardized_cluster->Forel2::standartization();    
    
  //  this->cluster2 = new Gkk( this->fname.toUtf8().data() );    //making cluster from input data
//    this->cluster2->clustering(this->clustersnumspinBox->text().QString::toInt(), 0.00001, 2);
  //  this->standardized_cluster2 = new Gkk( this->fname.toUtf8().data() ); //making standardized cluster
   // this->standardized_cluster2->Gkk::standartization();    
  //  this->standardized_cluster2->clustering(this->clustersnumspinBox->text().QString::toInt(), 0.001, 2);
    
    emit this->clustered();
}

void MainWindow::show_clustering()
{
    vector< Claster* > *mean_vector;
    vector< Claster* > *mean_vector2;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->clustered_data;
        mean_vector2 = &this->clustered_data2;
    }
    else
    {
        mean_vector = &this->clustered_standart_data;
        mean_vector2 = &this->clustered_standart_data2;
    }
    Claster* table = new Claster();  //creating cluster that include full clustered data
    Claster* table2 = new Claster();  //creating cluster that include full clustered data
    
    table->propnum = ( (*mean_vector)[0]->propnum ) + 1;
    for (int i = 0; i<(*mean_vector).size(); ++i)  //by clusters
    {
        for (int j=0; j<(*mean_vector)[i]->objects.size(); ++j)  //by objects in cluster
        {
            table->objects.push_back((*mean_vector)[i]->objects[j]);
            table->objects[table->objects.size()-1].push_back(i+1);
        }
    }
    
    table2->propnum = ( (*mean_vector2)[0]->propnum ) + 1;
    for (int i = 0; i<(*mean_vector2).size(); ++i)  //by clusters
    {
        for (int j=0; j<(*mean_vector2)[i]->objects.size(); ++j)  //by objects in cluster
        {
            table2->objects.push_back((*mean_vector2)[i]->objects[j]);
            table2->objects[table2->objects.size()-1].push_back(i+1);
        }
    }
    
    
    QString x = "x"; 
        
    this->afterclusterizatintableWidget->horizontalHeader()->setVisible(true);
    this->afterclusterizatintableWidget_2->horizontalHeader()->setVisible(true);
    
    fill_in_table(this->afterclusterizatintableWidget, table, x);
    delete(table);
    fill_in_table(this->afterclusterizatintableWidget_2, table2, x);
    delete(table2);

    
    QTableWidgetItem* newItem = new QTableWidgetItem(QTableWidgetItem::Type);
    newItem->setTextAlignment(Qt::AlignHCenter);         
    x=( QString::fromAscii("Y") );
    newItem->setText( x );
    this->afterclusterizatintableWidget->setHorizontalHeaderItem((*mean_vector)[0]->propnum, newItem);
    this->afterclusterizatintableWidget_2->setHorizontalHeaderItem((*mean_vector2)[0]->propnum, newItem);
    
    //this->afterclusterizatintableWidget->setSortingEnabled(true);
   // this->afterclusterizatintableWidget->sortByColumn(0, Qt::AscendingOrder);
}


void MainWindow::show_mean_values()
{
    vector< Claster* >* mean_vector;
    vector< Claster* >* mean_vector2;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->clustered_data;
        mean_vector2 = &this->clustered_data2;
    }
    else
    {
        mean_vector = &this->clustered_standart_data;
        mean_vector2 = &this->clustered_standart_data2;
    }
    QString x;
    QTableWidgetItem* newItem;
    QTableWidgetItem* newItem2;
    this->meanvaluetableWidget->setColumnCount((*mean_vector)[0]->propnum);
    this->meanvaluetableWidget->setRowCount((*mean_vector).size());
  
    this->meanvaluetableWidget_2->setColumnCount((*mean_vector2)[0]->propnum);
    this->meanvaluetableWidget_2->setRowCount((*mean_vector2).size());

    
    if ( (*mean_vector)[0]->propnum != 0) 
    {
        this->Q2tableWidget->setColumnCount(1);
        this->Q2tableWidget->setRowCount(this->Q2tableWidget->rowCount()+1);
        newItem = new QTableWidgetItem(QTableWidgetItem::Type);
        newItem->setTextAlignment(Qt::AlignHCenter);         
        newItem->setText(QString::number(Q2(*mean_vector)));
        this->Q2tableWidget->setColumnWidth(0, this->Q2tableWidget->width());
        this->Q2tableWidget->setItem(this->Q2tableWidget->rowCount()-1, 0, newItem);
    }
    

    if ( (*mean_vector2)[0]->propnum != 0) 
    {
        this->Q2tableWidget_2->setColumnCount(1);
        this->Q2tableWidget_2->setRowCount(this->Q2tableWidget_2->rowCount()+1);
        newItem2 = new QTableWidgetItem(QTableWidgetItem::Type);
        newItem2->setTextAlignment(Qt::AlignHCenter);         
        newItem2->setText(QString::number(Q2(*mean_vector2)));
        this->Q2tableWidget_2->setColumnWidth(0, this->Q2tableWidget_2->width());
        this->Q2tableWidget_2->setItem(this->Q2tableWidget_2->rowCount()-1, 0, newItem2);
    }


    
    vector< float > mean_values_cluster_vector;
    for (int i=0; i<(*mean_vector).size(); ++i)
    {
        mean_values_cluster_vector = (*mean_vector)[i]->count_center();
         for (int j=0; j<mean_values_cluster_vector.size(); ++j)
         {
             newItem = new QTableWidgetItem(QTableWidgetItem::Type);
             newItem->setTextAlignment(Qt::AlignHCenter);         
             x=(QString::number(i + 1) );
             newItem->setText( x );
             this->meanvaluetableWidget->setHorizontalHeaderItem(i, newItem);
             this->meanvaluetableWidget->setColumnWidth(i,
             ( (this->meanvaluetableWidget->width() - this->meanvaluetableWidget->verticalHeader()->defaultSectionSize()
                     -  this->meanvaluetableWidget->verticalScrollBar()->width() - 6 )/ (*mean_vector)[i]->propnum  ) );   
         } 
         for (int j=0; j<mean_values_cluster_vector.size(); ++j)
         {
             newItem = new QTableWidgetItem(QTableWidgetItem::Type);
             newItem->setText(QString::number(mean_values_cluster_vector[j]));
             newItem->setTextAlignment(Qt::AlignJustify);
             this->meanvaluetableWidget->removeCellWidget(i, j);
             this->meanvaluetableWidget->setItem(i, j, newItem);         
         }
        //mean_values_cluster_vector.clear();
    }
    
    
    vector< float > mean_values_cluster_vector2;
    for (int i=0; i<(*mean_vector2).size(); ++i)
    {
        mean_values_cluster_vector2 = (*mean_vector2)[i]->count_center();
         for (int j=0; j<mean_values_cluster_vector2.size(); ++j)
         {
             newItem2 = new QTableWidgetItem(QTableWidgetItem::Type);
             newItem2->setTextAlignment(Qt::AlignHCenter);         
             x=(QString::number(i + 1) );
             newItem2->setText( x );
             this->meanvaluetableWidget_2->setHorizontalHeaderItem(i, newItem2);
             this->meanvaluetableWidget_2->setColumnWidth(i,
             ( (this->meanvaluetableWidget_2->width() - this->meanvaluetableWidget_2->verticalHeader()->defaultSectionSize()
                     -  this->meanvaluetableWidget_2->verticalScrollBar()->width() - 6 )/ (*mean_vector2)[i]->propnum  ) );   
         } 
         for (int j=0; j<mean_values_cluster_vector2.size(); ++j)
         {
             newItem2 = new QTableWidgetItem(QTableWidgetItem::Type);
             newItem2->setText(QString::number(mean_values_cluster_vector2[j]));
             newItem2->setTextAlignment(Qt::AlignJustify);
             this->meanvaluetableWidget_2->removeCellWidget(i, j);
             this->meanvaluetableWidget_2->setItem(i, j, newItem2);         
         }
        //mean_values_cluster_vector.clear();
    }
    
    
}


void MainWindow::replot_by(int numofx, int numofy, vector< Claster*>& data, QwtPlot* p)
{
    int r,g,b;
    for (int i=0; i<this->curves_vector.size(); ++i)
    {
            delete(this->curves_vector[i]);
    }
    this->curves_vector.clear();
    for (int i=0; i<this->curves_vector2.size(); ++i)
    {
            delete(this->curves_vector2[i]);
    }
    this->curves_vector2.clear();

    
    for (int i=0; i<this->points_vector.size(); ++i)
    {
        this->points_vector[i]->clear();
    }
    for (int i=0; i<this->points_vector2.size(); ++i)
    {
        this->points_vector2[i]->clear();
    }
    
    
    for(int i=0; i<data.size(); ++i) //by clusters
    {
        this->points_vector.push_back(new QVector<QPointF>);
        this->curves_vector.push_back(new QwtPlotCurve());
        for (int j=0; j<data[i]->objects.size(); ++j)  //by objects
        {
            this->points_vector[i]->append(QPointF(data[i]->objects[j][numofx], data[i]->objects[j][numofy]));        
        }
        if (r > 125)
        {
            r = rand() % 130; // this->red;
        }
        else
        {
            r = rand() % 131 + 125;
        }
        if (g > 125)
        {
            g = rand() % 130; // this->red;
        }
        else
        {
            g = rand() % 131 + 125;
        }
        if (b > 125)
        {
            b = rand() % 130; // this->red;
        }
        else
        {
            b = rand() % 131 + 125;
        }
        
//        g = rand() % 255;//this->green; 
 //       b = rand() % 150 + 105;//this->blue;
        this->pen->setColor(QColor(r, g , b));
        this->curves_vector[i]->setPen(*this->pen);    
        this->curves_vector[i]->setSamples(*(this->points_vector[i]));
        this->curves_vector[i]->attach(p);
        this->curves_vector[i]->setStyle(QwtPlotCurve::Dots);        
    }
    p->replot();    
}


void MainWindow::replot_chart()
{
    vector<Claster*>* mean_vector;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->clustered_data2;
    }
    else
    {
        mean_vector = &this->clustered_standart_data2;
    }
    
/*    if(this->abradioButton->isChecked() == true)
    {  
       this->replot_by(0, 1, *mean_vector);
    }
    if (this->bcradioButton->isChecked() == true)
    {
        this->replot_by(1, 2, *mean_vector);
    }
    if (this->acradioButton->isChecked() == true)
    {
        this->replot_by(0, 2, *mean_vector);
    }*/
    
    this->replot_by(this->xaxisspinBox->text().toInt(), this->yaxisspinBox->text().toInt(), *mean_vector, this->qwtPlot_2);    
}

void MainWindow::show_membership()
{
    Claster* matrix;
    if (this->standartizationheckBox->isChecked() == false)
    {
        matrix = this->cluster2->get_membership_matrix();
    }
    else
    {
        matrix = this->standardized_cluster2->get_membership_matrix();
    }
    QString x = "";
    this->fill_in_table(membershiptableWidget, matrix, x);     
}

void MainWindow::show_centers()
{
    vector< vector< float > >* mean_vector;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->cluster2->centers;
    }
    else
    {
        mean_vector = &this->standardized_cluster2->centers;
    }
    Claster* tmp = new Claster();
    for (int i=0; i<(*mean_vector).size(); ++i)
    {
        tmp->add((*mean_vector)[i]);
    }
    tmp->propnum = (*mean_vector)[0].size();
    
    QString x = "";
    this->fill_in_table(tableWidget_2, tmp, x);    
    
    
    if (this->cluster2 != NULL)
    {
        delete(this->cluster2);
    }
    if (this->standardized_cluster2 != NULL)
    {
        delete(this->standardized_cluster2);
    }
    this->cluster2 = new Gkk( this->fname.toUtf8().data() );    //making cluster from input data
    this->standardized_cluster2 = new Gkk( this->fname.toUtf8().data() ); //making standardized cluster
    this->standardized_cluster2->Gkk::standartization();                    
    
}



MainWindow::MainWindow(QWidget* parent):QMainWindow(parent)
{    
    this->pen = new QPen();
       
    this->pen->setStyle(Qt::DotLine);
    this->pen->setWidth(7);
   
    srand(static_cast<unsigned>(time(NULL)));
    
    setupUi(this);
    connect(this->LoadFilepushButton, SIGNAL(released()), this, SLOT(get_file_name()) );
    connect(this->clusteringpushButton, SIGNAL(clicked()), this, SLOT(clustering()));        
    connect(this, SIGNAL(clustered()), this, SLOT(show_clustering()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(loading_data()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(clustering()));
    connect(this, SIGNAL(clustered()), this, SLOT(replot_chart()));    
    connect(this, SIGNAL(fname_got()), this, SLOT(loading_data()));
    connect(this, SIGNAL(clustered()), this, SLOT(show_mean_values()));
    connect(this, SIGNAL(clustered()), this, SLOT(show_membership()));
    connect(this, SIGNAL(clustered()), this, SLOT(show_centers()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(show_mean_values()));
    
    connect(this->abradioButton, SIGNAL(clicked()), this, SLOT(replot_chart()));
    connect(this->bcradioButton, SIGNAL(clicked()), this, SLOT(replot_chart()));
    connect(this->acradioButton, SIGNAL(clicked()), this, SLOT(replot_chart()));    
}
