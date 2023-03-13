#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDoubleSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_New_button_clicked();

    void on_Delete_button_clicked();

    void on_Update_button_clicked();

    void on_Sallary_Button_clicked();

    void on_Age_button_clicked();

    void on_Sallary_totalButton_clicked();

    void on_Age_totalButton_clicked();

    void on_Save_button_clicked();

    void on_Delete_totalButton_clicked();

    void on_Update_totalButton_clicked();

    void on_All_button_clicked();

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
