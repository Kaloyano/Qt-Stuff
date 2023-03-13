#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <graph_dialog.h>

#include <QMainWindow>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDoubleSpinBox>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVariant temp = 0;

    QString c;
    QStringList names;
    QChart *chart2 = new QChart();
    QBarCategoryAxis   *axis2 = new QBarCategoryAxis();

private slots:

    void on_Graph_button_clicked();

    void on_New_button_clicked();

    void on_Update_button_clicked();

    void on_Graph2_clicked();

    void on_Delete_button_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *table;
    QSqlTableModel *Company_table;
    QSqlDatabase db;
    QDoubleSpinBox *Age_box;
    QDoubleSpinBox *Salary_box;
    QDoubleSpinBox *Salary_totalBox;
    QDoubleSpinBox *Age_totalBox;
};
#endif // MAINWINDOW_H
