#ifndef PROJECTILEDIALOG_H
#define PROJECTILEDIALOG_H

#include <error_dialog.h>

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QComboBox>
#include <QList>
#include <QDebug>


namespace Ui {
class ProjectileDialog;
}
//------------------------------------------------------------------
class ProjectileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectileDialog(QWidget *parent = nullptr);
    ~ProjectileDialog();

private:
   bool PermitFlag;
//------------------------------------------------------------------
    Ui::ProjectileDialog *ui;
    QSpinBox *aSpinBox;
    QSpinBox *eleSpinBox;
    QSpinBox *qSpinBox;
    QSpinBox *zSpinBox;
    QLabel   *decayLabel;
    QLineEdit *eleLineEdit;
    QFrame *elementFrame;
//------------------------------------------------------------------
    QRadioButton *Energy_Radio;
    QSpinBox * Energy_spinBox;
    QRadioButton *TKE_Radio;
    QSpinBox * TKE_spinBox;
    QRadioButton *Brho_Radio;
    QSpinBox * Brho_spinBox;
    QRadioButton *P_Radio;
    QSpinBox * P_spinBox;
    QRadioButton *U_Radio;
    QSpinBox * U_spinBox;
    QGroupBox *Energy_Group;
//------------------------------------------------------------------
    QComboBox *X_1D_combo;
    QComboBox *X_2D_combo;
    QComboBox *X_correlated_combo;
    QComboBox *T_1D_combo;
    QComboBox *T_2D_combo;
    QComboBox *T_correlated_combo;
    QComboBox *Y_1D_combo;
    QComboBox *Y_2D_combo;
    QComboBox *Y_correlated_combo;
    QComboBox *P_1D_combo;
    QComboBox *P_2D_combo;
    QComboBox *P_correlated_combo;
    QComboBox *L_1D_combo;
    QComboBox *L_2D_combo;
    QComboBox *L_correlated_combo;
    QComboBox *D_1D_combo;
    QComboBox *D_2D_combo;
    QComboBox *D_correlated_combo;
    QGroupBox *Emmitance_group;
//------------------------------------------------------------------

    QSpinBox *Test; //delete this

    int neutronCount = 20;
    int protonCount = 20;
    int nucleonCount = protonCount+neutronCount;
    int Temp;

private slots:
    void on_Z_rightButton_clicked();
    void on_Z_leftButton_clicked();
    void on_N_leftButton_clicked();
    void on_N_rightButton_clicked();
    void on_Z_spinBox_valueChanged(int arg1);
    void on_A_spinBox_valueChanged(int arg1);
    void on_Energy_Radio_toggled(bool checked);
    void on_TKE_Radio_toggled(bool checked);
    void on_TKE_Radio_clicked();
    void on_Energy_Radio_clicked();
    void on_Brho_Radio_clicked();
    void on_P_Radio_clicked();
    void on_U_Radio_clicked();
    void on_X_check_toggled(bool checked);
    void on_T_check_toggled(bool checked);
    void on_Y_check_toggled(bool checked);
    void on_P_check_toggled(bool checked);
    void on_L_check_toggled(bool checked);
    void on_D_check_toggled(bool checked);
    void on_X_correlated_combo_currentIndexChanged(int index);
    void on_T_correlated_combo_currentIndexChanged(int index);
    void on_Y_correlated_combo_currentIndexChanged(int index);
    void on_P_correlated_combo_currentIndexChanged(int index);
    void on_L_correlated_combo_currentIndexChanged(int index);
    void on_D_correlated_combo_currentIndexChanged(int index);
    void on_X_2D_combo_currentIndexChanged(int index);
    void on_T_2D_combo_currentIndexChanged(int index);
    void on_Y_2D_combo_currentIndexChanged(int index);
    void on_P_2D_combo_currentIndexChanged(int index);
    void on_L_2D_combo_currentIndexChanged(int index);
    void on_D_2D_combo_currentIndexChanged(int index);
    void on_pushButton_clicked();
};

#endif // PROJECTILEDIALOG_H
