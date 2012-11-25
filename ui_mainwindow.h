/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Nov 25 13:32:57 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt/qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *maintabWidget;
    QWidget *tablestab;
    QTabWidget *clusteredtablestabWidget;
    QWidget *inputdatatab;
    QTableWidget *starttableWidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *LoadFilepushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *clustersnumspinBox;
    QPushButton *clusteringpushButton;
    QCheckBox *standartizationheckBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLCDNumber *Q2lcdNumber;
    QTableWidget *distancestableWidget;
    QLabel *label_2;
    QWidget *clusteredtab;
    QLabel *label_3;
    QTableWidget *meanvaluetableWidget;
    QTableWidget *afterclusterizatintableWidget;
    QLabel *label_5;
    QWidget *charttab;
    QwtPlot *qwtPlot;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *abradioButton;
    QRadioButton *bcradioButton;
    QRadioButton *acradioButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(889, 588);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setInputMethodHints(Qt::ImhHiddenText);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        maintabWidget = new QTabWidget(centralwidget);
        maintabWidget->setObjectName(QString::fromUtf8("maintabWidget"));
        maintabWidget->setGeometry(QRect(0, 0, 891, 591));
        sizePolicy.setHeightForWidth(maintabWidget->sizePolicy().hasHeightForWidth());
        maintabWidget->setSizePolicy(sizePolicy);
        maintabWidget->setContextMenuPolicy(Qt::PreventContextMenu);
        maintabWidget->setInputMethodHints(Qt::ImhHiddenText);
        maintabWidget->setTabPosition(QTabWidget::North);
        maintabWidget->setTabShape(QTabWidget::Rounded);
        maintabWidget->setElideMode(Qt::ElideNone);
        tablestab = new QWidget();
        tablestab->setObjectName(QString::fromUtf8("tablestab"));
        clusteredtablestabWidget = new QTabWidget(tablestab);
        clusteredtablestabWidget->setObjectName(QString::fromUtf8("clusteredtablestabWidget"));
        clusteredtablestabWidget->setGeometry(QRect(0, 0, 891, 561));
        clusteredtablestabWidget->setTabPosition(QTabWidget::West);
        inputdatatab = new QWidget();
        inputdatatab->setObjectName(QString::fromUtf8("inputdatatab"));
        starttableWidget = new QTableWidget(inputdatatab);
        starttableWidget->setObjectName(QString::fromUtf8("starttableWidget"));
        starttableWidget->setGeometry(QRect(490, 40, 331, 351));
        starttableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        starttableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        starttableWidget->setAutoScroll(false);
        starttableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        starttableWidget->setDragDropOverwriteMode(false);
        starttableWidget->setAlternatingRowColors(false);
        starttableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        starttableWidget->setTextElideMode(Qt::ElideRight);
        starttableWidget->setShowGrid(true);
        starttableWidget->setSortingEnabled(false);
        starttableWidget->setWordWrap(true);
        starttableWidget->setCornerButtonEnabled(false);
        starttableWidget->setRowCount(0);
        starttableWidget->setColumnCount(0);
        starttableWidget->horizontalHeader()->setVisible(false);
        starttableWidget->horizontalHeader()->setDefaultSectionSize(100);
        starttableWidget->horizontalHeader()->setHighlightSections(true);
        starttableWidget->horizontalHeader()->setMinimumSectionSize(27);
        starttableWidget->verticalHeader()->setHighlightSections(true);
        label = new QLabel(inputdatatab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(490, 20, 151, 16));
        verticalLayoutWidget = new QWidget(inputdatatab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(520, 400, 261, 156));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LoadFilepushButton = new QPushButton(verticalLayoutWidget);
        LoadFilepushButton->setObjectName(QString::fromUtf8("LoadFilepushButton"));
        LoadFilepushButton->setFlat(false);

        verticalLayout->addWidget(LoadFilepushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        clustersnumspinBox = new QSpinBox(verticalLayoutWidget);
        clustersnumspinBox->setObjectName(QString::fromUtf8("clustersnumspinBox"));
        clustersnumspinBox->setMinimum(1);
        clustersnumspinBox->setMaximum(99999999);

        horizontalLayout_2->addWidget(clustersnumspinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        clusteringpushButton = new QPushButton(verticalLayoutWidget);
        clusteringpushButton->setObjectName(QString::fromUtf8("clusteringpushButton"));

        verticalLayout->addWidget(clusteringpushButton);

        standartizationheckBox = new QCheckBox(verticalLayoutWidget);
        standartizationheckBox->setObjectName(QString::fromUtf8("standartizationheckBox"));
        standartizationheckBox->setChecked(false);
        standartizationheckBox->setAutoExclusive(true);

        verticalLayout->addWidget(standartizationheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        Q2lcdNumber = new QLCDNumber(verticalLayoutWidget);
        Q2lcdNumber->setObjectName(QString::fromUtf8("Q2lcdNumber"));
        Q2lcdNumber->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(Q2lcdNumber);


        verticalLayout->addLayout(horizontalLayout);

        distancestableWidget = new QTableWidget(inputdatatab);
        distancestableWidget->setObjectName(QString::fromUtf8("distancestableWidget"));
        distancestableWidget->setGeometry(QRect(10, 40, 441, 511));
        distancestableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        distancestableWidget->setAutoScroll(false);
        distancestableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        distancestableWidget->setDragDropOverwriteMode(false);
        distancestableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        distancestableWidget->setTextElideMode(Qt::ElideMiddle);
        distancestableWidget->setCornerButtonEnabled(false);
        label_2 = new QLabel(inputdatatab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 151, 16));
        clusteredtablestabWidget->addTab(inputdatatab, QString());
        clusteredtab = new QWidget();
        clusteredtab->setObjectName(QString::fromUtf8("clusteredtab"));
        label_3 = new QLabel(clusteredtab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 171, 16));
        meanvaluetableWidget = new QTableWidget(clusteredtab);
        meanvaluetableWidget->setObjectName(QString::fromUtf8("meanvaluetableWidget"));
        meanvaluetableWidget->setGeometry(QRect(20, 40, 371, 501));
        meanvaluetableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        meanvaluetableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        meanvaluetableWidget->setAutoScroll(false);
        meanvaluetableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        meanvaluetableWidget->setDragDropOverwriteMode(false);
        meanvaluetableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        meanvaluetableWidget->setTextElideMode(Qt::ElideMiddle);
        meanvaluetableWidget->setCornerButtonEnabled(false);
        afterclusterizatintableWidget = new QTableWidget(clusteredtab);
        afterclusterizatintableWidget->setObjectName(QString::fromUtf8("afterclusterizatintableWidget"));
        afterclusterizatintableWidget->setGeometry(QRect(410, 40, 431, 501));
        afterclusterizatintableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        afterclusterizatintableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        afterclusterizatintableWidget->setAutoScroll(false);
        afterclusterizatintableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        afterclusterizatintableWidget->setDragDropOverwriteMode(false);
        afterclusterizatintableWidget->setAlternatingRowColors(false);
        afterclusterizatintableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        afterclusterizatintableWidget->setTextElideMode(Qt::ElideRight);
        afterclusterizatintableWidget->setShowGrid(true);
        afterclusterizatintableWidget->setSortingEnabled(false);
        afterclusterizatintableWidget->setWordWrap(true);
        afterclusterizatintableWidget->setCornerButtonEnabled(false);
        afterclusterizatintableWidget->setRowCount(0);
        afterclusterizatintableWidget->setColumnCount(0);
        afterclusterizatintableWidget->horizontalHeader()->setVisible(false);
        afterclusterizatintableWidget->horizontalHeader()->setDefaultSectionSize(100);
        afterclusterizatintableWidget->horizontalHeader()->setMinimumSectionSize(27);
        label_5 = new QLabel(clusteredtab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(410, 20, 201, 16));
        clusteredtablestabWidget->addTab(clusteredtab, QString());
        maintabWidget->addTab(tablestab, QString());
        charttab = new QWidget();
        charttab->setObjectName(QString::fromUtf8("charttab"));
        qwtPlot = new QwtPlot(charttab);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
        qwtPlot->setGeometry(QRect(0, 0, 861, 511));
        qwtPlot->setFrameShape(QFrame::StyledPanel);
        groupBox = new QGroupBox(charttab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(150, 489, 471, 61));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 377, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        abradioButton = new QRadioButton(horizontalLayoutWidget);
        abradioButton->setObjectName(QString::fromUtf8("abradioButton"));
        abradioButton->setChecked(true);

        horizontalLayout_3->addWidget(abradioButton);

        bcradioButton = new QRadioButton(horizontalLayoutWidget);
        bcradioButton->setObjectName(QString::fromUtf8("bcradioButton"));

        horizontalLayout_3->addWidget(bcradioButton);

        acradioButton = new QRadioButton(horizontalLayoutWidget);
        acradioButton->setObjectName(QString::fromUtf8("acradioButton"));

        horizontalLayout_3->addWidget(acradioButton);

        maintabWidget->addTab(charttab, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        maintabWidget->setCurrentIndex(0);
        clusteredtablestabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        maintabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "Input data:", 0, QApplication::UnicodeUTF8));
        LoadFilepushButton->setText(QApplication::translate("MainWindow", "Load file", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Number of clusters:", 0, QApplication::UnicodeUTF8));
        clusteringpushButton->setText(QApplication::translate("MainWindow", "Clustering", 0, QApplication::UnicodeUTF8));
        standartizationheckBox->setText(QApplication::translate("MainWindow", "Standartization", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Quality functional(Q2)=", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Matrix of distances:", 0, QApplication::UnicodeUTF8));
        clusteredtablestabWidget->setTabText(clusteredtablestabWidget->indexOf(inputdatatab), QApplication::translate("MainWindow", "Input data", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Mean value of clusters:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Data after clusterization:", 0, QApplication::UnicodeUTF8));
        clusteredtablestabWidget->setTabText(clusteredtablestabWidget->indexOf(clusteredtab), QApplication::translate("MainWindow", "Clustered data", 0, QApplication::UnicodeUTF8));
        maintabWidget->setTabText(maintabWidget->indexOf(tablestab), QApplication::translate("MainWindow", "Tables", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        abradioButton->setText(QApplication::translate("MainWindow", "Properties 1x2", 0, QApplication::UnicodeUTF8));
        bcradioButton->setText(QApplication::translate("MainWindow", "Properties 2x3", 0, QApplication::UnicodeUTF8));
        acradioButton->setText(QApplication::translate("MainWindow", "Properties 1x3", 0, QApplication::UnicodeUTF8));
        maintabWidget->setTabText(maintabWidget->indexOf(charttab), QApplication::translate("MainWindow", "Chart", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
