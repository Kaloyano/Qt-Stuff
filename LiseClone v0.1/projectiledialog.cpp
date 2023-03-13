#include "projectiledialog.h"
#include "ui_projectiledialog.h"
#include <QFrame>
#include <QGroupBox>
#include <QDesktopServices>
#include <QUrl>
#include <QComboBox>
#include <QList>
#include <QDebug>

//------------------------------------------------------------------------------------------------------------------------------------
ProjectileDialog::ProjectileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectileDialog)
{
    ui->setupUi(this);
    PermitFlag=false;
//Element Data------------------------------------------------------------------------------------------------------------------------
    ui->elementFrame->setStyleSheet(".QFrame{background-color: light grey; border: 1px solid #006020; border-radius: 10px;}");

    ui->Z_spinBox->setValue(protonCount);
    ui->A_spinBox->setValue(nucleonCount);
    ui->Q_spinBox->setValue(protonCount);

    if(neutronCount == protonCount)
    {
        ui->decayLabel->setText(QString("Stable"));
    }
    else
    {
        ui->decayLabel->setText(QString("Decaying"));
    }

    ui->eleLineEdit->setText(QString("WP"));

//Beam Energy-------------------------------------------------------------------------------------------------------------------------
    ui->Energy_Group->setStyleSheet(".QGroupBox{background-color: light grey; border: 1px solid #006020; border-radius: 10px;}");
    ui->TKE_spinBox->setDisabled(true);
    ui->Brho_spinBox->setDisabled(true);
    ui->P_spinBox->setDisabled(true);
    ui->U_spinBox->setDisabled(true);
//Emittance-------------------------------------------------------------------------------------------------------------------------
    ui->Emmitance_group->setStyleSheet(".QGroupBox{background-color: light grey; border: 1px solid #006020; border-radius: 10px;}");
    ui->X_2D_combo->setVisible(false);
    ui->T_2D_combo->setVisible(false);
    ui->Y_2D_combo->setVisible(false);
    ui->P_2D_combo->setVisible(false);
    ui->L_2D_combo->setVisible(false);
    ui->D_2D_combo->setVisible(false);

    ui->X_correlated_combo->setVisible(false);
    ui->T_correlated_combo->setVisible(false);
    ui->Y_correlated_combo->setVisible(false);
    ui->P_correlated_combo->setVisible(false);
    ui->L_correlated_combo->setVisible(false);
    ui->D_correlated_combo->setVisible(false);

//------------------------------------------------------------------------------------------------------------------------------------
    //This one has objects I don't want and I don't know how to iterate through it and skip certain objects
    QList<QComboBox*> combo = findChildren<QComboBox*>();
        qDebug() << combo.size();
        qDebug() << combo;
        //ui->combo[1]->setVisible(false);

    // The For loop makes all combo boxes invisible I tried to do if(i == 1) but it throws an error

    //QList<QComboBox*>::Iterator i;
    //for(i=combo.begin(); i !=combo.end(); ++i)
    //{
        //(*i)->setVisible(false);
    //}



    //This one doesn't work
    QList<QComboBox*> combos;
        combos.append(X_2D_combo);

        qDebug() << combos.size();
        qDebug() << combos;
//------------------------------------------------------------------------------------------------------------------------------------


    PermitFlag=true;

}
//------------------------------------------------------------------------------------------------------------------------------------
ProjectileDialog::~ProjectileDialog()
{
    delete ui;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Z_rightButton_clicked()
{
    protonCount += 1;
    ui->Z_spinBox->setValue(protonCount);
    ui->Q_spinBox->setValue(protonCount);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Z_leftButton_clicked()
{
    protonCount -= 1;
    ui->Z_spinBox->setValue(protonCount);
    ui->Q_spinBox->setValue(protonCount);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_N_rightButton_clicked()
{
    neutronCount += 1;
    nucleonCount = protonCount+neutronCount;
    ui->A_spinBox->setValue(nucleonCount);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_N_leftButton_clicked()
{
    neutronCount -= 1;
    nucleonCount = protonCount+neutronCount;
    ui->A_spinBox->setValue(nucleonCount);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Z_spinBox_valueChanged(int p_Num)
{
if(!PermitFlag) return;

    protonCount = p_Num;
    nucleonCount = protonCount+neutronCount;

    PermitFlag=false;

    ui->A_spinBox->setValue(nucleonCount);
    ui->Q_spinBox->setValue(protonCount);

    if(neutronCount == protonCount)
    {
        ui->decayLabel->setText(QString("Stable"));
    }
    else
    {
        ui->decayLabel->setText(QString("Decaying"));
    }

    PermitFlag=true;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_A_spinBox_valueChanged(int nucleonValue)
{
    neutronCount = nucleonValue-protonCount;

    if(neutronCount == protonCount)
    {
        ui->decayLabel->setText(QString("Stable"));
    }
    else
    {
        ui->decayLabel->setText(QString("Decaying"));
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Energy_Radio_clicked()
{
    ui->Energy_spinBox->setEnabled(true);
    ui->TKE_spinBox->setDisabled(true);
    ui->Brho_spinBox->setDisabled(true);
    ui->P_spinBox->setDisabled(true);
    ui->U_spinBox->setDisabled(true);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_TKE_Radio_clicked()
{
    ui->TKE_spinBox->setEnabled(true);
    ui->Energy_spinBox->setDisabled(true);
    ui->Brho_spinBox->setDisabled(true);
    ui->P_spinBox->setDisabled(true);
    ui->U_spinBox->setDisabled(true);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Brho_Radio_clicked()
{
    ui->Brho_spinBox->setEnabled(true);
    ui->Energy_spinBox->setDisabled(true);
    ui->TKE_spinBox->setDisabled(true);
    ui->P_spinBox->setDisabled(true);
    ui->U_spinBox->setDisabled(true);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_P_Radio_clicked()
{
    ui->P_spinBox->setEnabled(true);
    ui->Energy_spinBox->setDisabled(true);
    ui->Brho_spinBox->setDisabled(true);
    ui->TKE_spinBox->setDisabled(true);
    ui->U_spinBox->setDisabled(true);
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_U_Radio_clicked()
{
    ui->U_spinBox->setEnabled(true);
    ui->Energy_spinBox->setDisabled(true);
    ui->Brho_spinBox->setDisabled(true);
    ui->P_spinBox->setDisabled(true);
    ui->TKE_spinBox->setDisabled(true);
}
//------------------------------------------------------------------------------------------------------------------------------------
// Need these other wise lines 193 and 194 in moc_projectiledialog.cpp throw out a ton of errors
void ProjectileDialog::on_Energy_Radio_toggled(bool checked)
{
    if(checked == true)
    {

    }
}
void ProjectileDialog::on_TKE_Radio_toggled(bool checked)
{
    if(checked == true)
    {

    }
}
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_X_check_toggled(bool checked)
{
    if(checked==true)
    {
        ui->X_2D_combo->setVisible(true);
        ui->X_correlated_combo->setVisible(true);
        ui->X_1D_combo->setDisabled(true);
        ui->X_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->X_2D_combo->setVisible(false);
        ui->X_correlated_combo->setVisible(false);
        ui->X_1D_combo->setDisabled(false);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_T_check_toggled(bool checked)
{
if(!PermitFlag) return;
    if(checked==true)
    {
        ui->T_2D_combo->setVisible(true);
        ui->T_correlated_combo->setVisible(true);
        ui->T_1D_combo->setDisabled(true);
        ui->T_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->T_2D_combo->setVisible(false);
        ui->T_correlated_combo->setVisible(false);
        ui->T_1D_combo->setDisabled(false);
    }
    PermitFlag=true;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Y_check_toggled(bool checked)
{
    if(checked==true)
    {
        ui->Y_2D_combo->setVisible(true);
        ui->Y_correlated_combo->setVisible(true);
        ui->Y_1D_combo->setDisabled(true);
        ui->Y_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->Y_2D_combo->setVisible(false);
        ui->Y_correlated_combo->setVisible(false);
        ui->Y_1D_combo->setDisabled(false);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_P_check_toggled(bool checked)
{
    if(checked==true)
    {
        ui->P_2D_combo->setVisible(true);
        ui->P_correlated_combo->setVisible(true);
        ui->P_1D_combo->setDisabled(true);
        ui->P_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->P_2D_combo->setVisible(false);
        ui->P_correlated_combo->setVisible(false);
        ui->P_1D_combo->setDisabled(false);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_L_check_toggled(bool checked)
{
    if(checked==true)
    {
        ui->L_2D_combo->setVisible(true);
        ui->L_correlated_combo->setVisible(true);
        ui->L_1D_combo->setDisabled(true);
        ui->L_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->L_2D_combo->setVisible(false);
        ui->L_correlated_combo->setVisible(false);
        ui->L_1D_combo->setDisabled(false);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_D_check_toggled(bool checked)
{
    if(checked==true)
    {
        ui->D_2D_combo->setVisible(true);
        ui->D_correlated_combo->setVisible(true);
        ui->D_1D_combo->setDisabled(true);
        ui->D_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->D_2D_combo->setVisible(false);
        ui->D_correlated_combo->setVisible(false);
        ui->D_1D_combo->setDisabled(false);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
// Should I have made the stuff below on activated instead of changed
// I say this becuase i think that I might create an infinite loop
// and i don't know if the permit stuff will work
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_X_correlated_combo_currentIndexChanged(int index)
{
if(!PermitFlag) return;
    if(index==1)
    {
        ui->X_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();

    }
    if(index==2)
    {
        Temp = ui->T_correlated_combo->currentIndex();
        if(Temp != 0 && Temp != 1)
        {
            ui->X_correlated_combo->setCurrentIndex(0);
            (new Error_Dialog())->exec();
        }
        else
        {
            ui->T_check->setChecked(true);
            ui->T_correlated_combo->setCurrentIndex(1);
            //ui->T_correlated_combo->setDisabled(true);
            //ui->T_2D_combo->setDisabled(true);
        }
    }

    PermitFlag=true;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_T_correlated_combo_currentIndexChanged(int index)
{
if(!PermitFlag) return;
    if(index==2)
    {
        ui->T_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();
    }
    PermitFlag=true;
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Y_correlated_combo_currentIndexChanged(int index)
{
    if(index==3)
    {
        ui->Y_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();

    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_P_correlated_combo_currentIndexChanged(int index)
{
    if(index==4)
    {
        ui->P_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();

    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_L_correlated_combo_currentIndexChanged(int index)
{
    if(index==5)
    {
        ui->L_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();

    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_D_correlated_combo_currentIndexChanged(int index)
{
    if(index==6)
    {
        ui->D_correlated_combo->setCurrentIndex(0);
        (new Error_Dialog())->exec();

    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_X_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->X_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->X_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_T_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->T_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->T_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_Y_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->Y_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->Y_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_P_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->P_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->P_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_L_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->L_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->L_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_D_2D_combo_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->D_1D_combo->setCurrentIndex(3);
    }
    else
    {
        ui->D_1D_combo->setCurrentIndex(2);
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
void ProjectileDialog::on_pushButton_clicked()
{
    QString link = "https://lise.nscl.msu.edu/9_2/9_2_85/9_2_88_shapes.pdf";
    QDesktopServices::openUrl(QUrl(link));
}

