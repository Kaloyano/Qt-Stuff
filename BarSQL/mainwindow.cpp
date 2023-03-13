#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetSelectionRange>
#include <QString>
#include <QLogValueAxis>
#define ACCESS "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};" \
    "FIL={MS Access};DBQ=C:\\Users\\kaloy\\Desktop\\QT\\Sql.mdb"

//------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(ACCESS);
    db.open();
    if(!db.open())
    {
        qDebug() << "Didn't open";
    }

    table = new QSqlTableModel(this);
    table->setTable("person");
    table->select();
    ui->tableView->setModel(table);

    Company_table = new QSqlTableModel(this);
    Company_table->setTable("company");
    Company_table->select();
    ui->Company_table->setModel(Company_table);
//------------------------------------------------------------------
    QSqlQuery query;
    query.exec("SELECT * FROM person [Salary]");
    QBarSet *set2 = new QBarSet("Salary");
    QBarSet *set3 = new QBarSet("Age");

    int count = 0;
    double v = 0;
//------------------------------------------------------------------
    while(query.next())
    {
        temp = query.value(3);
        v = temp.toDouble();
                                        qDebug() << v ;
        set2->insert(count,v);
//-------------------------------
        temp = query.value(2);
        v = temp.toDouble();
                                        qDebug() << v ;
        set3->insert(count,v);
//-------------------------------
        temp = query.value(1);
        c = temp.toString();
                                        qDebug() << c ;
        names << c;
    }
    qDebug() << set2 ;
    qDebug() << set3 ;
    qDebug() << names ;
//------------------------------------------------------------------
    QBarSeries *series2 = new QBarSeries();
    series2->append(set2);
    series2->append(set3);
//------------------------------------------------------------------
    chart2->addSeries(series2);
    chart2 ->setTitle("BarChart Example");
    chart2-> setAnimationOptions(QChart::SeriesAnimations);
//------------------------------------------------------------------
    QLogValueAxis *axisY = new QLogValueAxis();
    double maxValue = set3->at(0);
    for (int i = 1; i < set3->count(); ++i)
    {
        maxValue = qMax(maxValue, set3->at(i));
    }
    axisY->setRange(0, qMax(0.0, maxValue));
    axisY->setLabelFormat("%g ");
    chart2->addAxis(axisY, Qt::AlignLeft);
    series2->attachAxis(axisY);

    axis2 ->append(names);
    chart2->setAxisX(axis2,series2);
//------------------------------------------------------------------
    QChartView *chartView2 = new QChartView(chart2);
    chartView2->setParent(ui->horizontalFrame2);

}
//------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------
void MainWindow::on_Graph_button_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM person [Salary]");

    QBarSet *set2 = new QBarSet("Salary");
    QBarSet *set3 = new QBarSet("Age");

    int count = 0;
    double v = 0;
    while(query.next())
    {
        temp = query.value(3);
        v = temp.toDouble();
                                        qDebug() << v ;
        set2->insert(count,v);
//-------------------------------
        temp = query.value(2);
        v = temp.toDouble();
                                        qDebug() << v ;
        set3->insert(count,v);
//-------------------------------
        temp = query.value(1);
        c = temp.toString();
                                        qDebug() << c ;
        names << c;
    }

    axis2->clear();
    chart2->removeAllSeries();

    QBarSeries *series2 = new QBarSeries();
    series2->append(set2);
    series2->append(set3);
    chart2->addSeries(series2);


    QLogValueAxis *existingYAxis = chart2->findChild<QLogValueAxis*>();
    chart2->removeAxis(existingYAxis);

    QLogValueAxis *axisY = new QLogValueAxis();
    axisY->setTitleText("Values");
    axisY->setLabelFormat("%g");
    axisY->setBase(8.0);
    axisY->setMinorTickCount(-1);
    chart2->addAxis(axisY, Qt::AlignLeft);
    series2->attachAxis(axisY);

    axis2->append(names);
    chart2->update();

}
//------------------------------------------------------------------
void MainWindow::on_New_button_clicked()
{
    table->insertRow(ui->tableView->currentIndex().row());
}
//------------------------------------------------------------------
void MainWindow::on_Update_button_clicked()
{
    table->select();
}
//------------------------------------------------------------------
void MainWindow::on_Graph2_clicked()
{
    qDebug() <<"does nothing right now";
}
//------------------------------------------------------------------
void MainWindow::on_Delete_button_clicked()
{
    table->removeRow(ui->tableView->currentIndex().row());
}

