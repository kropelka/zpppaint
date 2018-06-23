#ifndef CONTRASTDIALOG_H
#define CONTRASTDIALOG_H

#include <QDialog>

namespace Ui {
class ContrastDialog;
}

class ContrastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContrastDialog(QWidget *parent = 0);
    ~ContrastDialog();
public slots:
    int setK();

private:
    Ui::ContrastDialog *ui;
};

#endif // CONTRASTDIALOG_H
