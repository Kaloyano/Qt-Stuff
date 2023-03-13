#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
//------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------------------------
void MainWindow::on_actionExit_triggered()
{
    QApplication:: quit();
}

//------------------------------------------------------------------
void MainWindow::on_actionOpen_triggered()
{

}

//------------------------------------------------------------------
void MainWindow::on_actionProjectile_triggered()
{
    (new ProjectileDialog())->exec();
}

