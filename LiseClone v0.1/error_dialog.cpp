#include "error_dialog.h"
#include "ui_error_dialog.h"

Error_Dialog::Error_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Error_Dialog)
{
    ui->setupUi(this);
}

Error_Dialog::~Error_Dialog()
{
    delete ui;
}
