#ifndef GRAPH_DIALOG_H
#define GRAPH_DIALOG_H

#include <QDialog>

namespace Ui {
class Graph_Dialog;
}

class Graph_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Graph_Dialog(QWidget *parent = nullptr);
    ~Graph_Dialog();

private:
    Ui::Graph_Dialog *ui;
};

#endif // GRAPH_DIALOG_H
