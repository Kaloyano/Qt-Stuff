#ifndef ERROR_DIALOG_H
#define ERROR_DIALOG_H

#include <QDialog>

namespace Ui {
class Error_Dialog;
}

class Error_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Error_Dialog(QWidget *parent = nullptr);
    ~Error_Dialog();

private:
    Ui::Error_Dialog *ui;
};

#endif // ERROR_DIALOG_H
