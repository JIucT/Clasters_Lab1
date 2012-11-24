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
     emit this->fname_got();     
}


void MainWindow::loading_data()
{
   if (this->fname.isEmpty() == false)
   {
         

     if (this->cluster != NULL)
     {
         delete(this->cluster);
     }
     this->cluster = new Forel2( this->fname.toUtf8().data() );    //making cluster from input data
     if (this->standardized_cluster != NULL)
     {
         delete(this->standardized_cluster);
     }
     this->standardized_cluster = new Forel2( this->fname.toUtf8().data() ); //making standardized cluster
     this->standardized_cluster->Forel2::standartization();  
     
     
     Forel2* mean_cluster;
     if (this->standartizationheckBox->isChecked() == false)
     {
         mean_cluster = this->cluster;         //showing unstandardized cluster
     }
     else
     {
         mean_cluster = this->standardized_cluster; //else showing standardized cluster
     }
     //showing cluster
     QString tmpstr = "x";
     fill_in_table(this->starttableWidget, mean_cluster->claster, tmpstr);
   //  this->starttableWidget->setSortingEnabled(true);
    // this->starttableWidget->sortByColumn(0, Qt::AscendingOrder);
     
     //showing distances matrix
     Claster* tmp;
     tmp = mean_cluster->get_distances_matrix();
     tmpstr = "";
     fill_in_table(this->distancestableWidget, tmp, tmpstr);
     for (int i=0; i<tmp->objects.size(); ++i)
     {
         this->distancestableWidget->setColumnWidth(i, 70);
     }
//     this->distancestableWidget->setSortingEnabled(true);
 //    this->distancestableWidget->sortByColumn(0, Qt::AscendingOrder);
     
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
                                     Forel2::clustering(this->clustersnumspinBox->text().QString::toInt(), 0.00001);    
    if (this->cluster != NULL)
    {
        delete(this->cluster);
    }
    if (this->standardized_cluster != NULL)
    {
        delete(this->standardized_cluster);
    }
    this->cluster = new Forel2( this->fname.toUtf8().data() );    //making cluster from input data
    this->standardized_cluster = new Forel2( this->fname.toUtf8().data() ); //making standardized cluster
    this->standardized_cluster->Forel2::standartization();    
    emit this->clustered();
}

void MainWindow::show_clustering()
{
    vector< Claster* > *mean_vector;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->clustered_data;
    }
    else
    {
        mean_vector = &this->clustered_standart_data;
    }
    Claster* table = new Claster();  //creating cluster that include full clustered data
    table->propnum = ( (*mean_vector)[0]->propnum ) + 1;
    for (int i = 0; i<(*mean_vector).size(); ++i)  //by clusters
    {
        for (int j=0; j<(*mean_vector)[i]->objects.size(); ++j)  //by objects in cluster
        {
            table->objects.push_back((*mean_vector)[i]->objects[j]);
            table->objects[table->objects.size()-1].push_back(i+1);
        }
    }
    QString x = "x"; 
    
    
    this->afterclusterizatintableWidget->horizontalHeader()->setVisible(true);
    fill_in_table(this->afterclusterizatintableWidget, table, x);
    delete(table);
   
    QTableWidgetItem* newItem = new QTableWidgetItem(QTableWidgetItem::Type);
    newItem->setTextAlignment(Qt::AlignHCenter);         
    x=( QString::fromAscii("Y") );
    newItem->setText( x );
    this->afterclusterizatintableWidget->setHorizontalHeaderItem((*mean_vector)[0]->propnum, newItem);
    
    //this->afterclusterizatintableWidget->setSortingEnabled(true);
   // this->afterclusterizatintableWidget->sortByColumn(0, Qt::AscendingOrder);
}


void MainWindow::show_mean_values()
{
    vector< Claster* >* mean_vector;
    if (this->standartizationheckBox->isChecked() == false)
    {
        mean_vector = &this->clustered_data;
    }
    else
    {
        mean_vector = &this->clustered_standart_data;
    }
    QString x;
    QTableWidgetItem* newItem;
    this->meanvaluetableWidget->setColumnCount((*mean_vector)[0]->propnum);
    this->meanvaluetableWidget->setRowCount((*mean_vector).size());

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
}

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent)
{
    setupUi(this);
    connect(this->LoadFilepushButton, SIGNAL(released()), this, SLOT(get_file_name()) );
    connect(this->clusteringpushButton, SIGNAL(clicked()), this, SLOT(clustering()));        
    connect(this, SIGNAL(clustered()), this, SLOT(show_clustering()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(loading_data()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(clustering()));
    connect(this, SIGNAL(fname_got()), this, SLOT(loading_data()));
    connect(this, SIGNAL(clustered()), this, SLOT(show_mean_values()));
    connect(this->standartizationheckBox, SIGNAL(toggled(bool)), this, SLOT(show_mean_values()));
}
