#include "graph_dialog.h"
#include "ui_graph_dialog.h"

Graph_Dialog::Graph_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph_Dialog)
{
    ui->setupUi(this);
}

Graph_Dialog::~Graph_Dialog()
{
    delete ui;
}
