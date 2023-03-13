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
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void addValues(int id, double tSalary, double avgSalary, double tAge, double avgAge)
{
    QSqlQuery query;

    query.prepare("INSERT INTO company ("
                  "ID,"
                  "[Total Salary],"
                  "[Avg Salary],"
                  "[Total Age],"
                  "[Avg Age])"
                  "VALUES (?,?,?,?,?);");

    query.addBindValue(id);
    query.addBindValue(tSalary);
    query.addBindValue(avgSalary);
    query.addBindValue(tAge);
    query.addBindValue(avgAge);

    if(!query.exec())
    {
        qDebug() <<"something broke" ;
    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_New_button_clicked()
{
    table->insertRow(ui->tableView->currentIndex().row());
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Delete_button_clicked()
{
    table->removeRow(ui->tableView->currentIndex().row());
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Update_button_clicked()
{
    table->select();
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Sallary_Button_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM person [Salary]");

    QVariant total = 0;
    double count = 0;
    double truetot = 0;

    while(query.next())
    {
        count += 1;
        total = query.value(3);
        truetot = total.value<double>()+truetot;
        ui->Salary_box->setValue(truetot/count);
    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Age_button_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM person [Age]");

    QVariant total = 0;
    double count = 0;
    double truetot = 0;

    while(query.next())
    {
        count += 1;
        total = query.value(2);
        truetot = total.value<double>()+truetot;
        ui->Age_box->setValue(truetot/count);
    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Sallary_totalButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM person [Salary]");

    QVariant total = 0;
    double truetotal = 0;

    while(query.next())
    {
        total = query.value(3);
        truetotal = total.value<double>()+truetotal;
    }
    ui->Salary_totalBox->setValue(truetotal);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Age_totalButton_clicked()
{
    QSqlQuery query;
    query.exec("SELECT * FROM person [Age]");

    QVariant total = 0;
    double truetotal = 0;

    while(query.next())
    {
        total = query.value(2);
        truetotal = total.value<double>()+truetotal;
    }
    ui->Age_totalBox->setValue(truetotal);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Save_button_clicked()
{
    double count = 0;
    double tS = 0;
    double aS = 0;
    double tA = 0;
    double aA = 0;

    QSqlQuery query;
    query.exec("SELECT * FROM company [Total Age]"); // what does [Total Age] do

    while(query.next())
    {
        count +=1;
    }

    tS = ui->Salary_totalBox->value();
    aS = ui->Salary_box->value();
    tA = ui->Age_totalBox->value();
    aA = ui->Age_box->value();

    addValues(count,tS,aS,tA,aA);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Delete_totalButton_clicked()
{
    Company_table->removeRow(ui->Company_table->currentIndex().row());
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_Update_totalButton_clicked()
{
    Company_table->select();
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void MainWindow::on_All_button_clicked()
{
    // why do I need emit here?
    emit ui->Age_button->clicked(true);
    emit ui->Age_totalButton->clicked(true);
    emit ui->Sallary_totalButton->clicked(true);
    emit ui->Sallary_Button->clicked(true);
}

