#ifndef SELECTCOLORDIALOG_H
#define SELECTCOLORDIALOG_H

#include <QDialog>

namespace Ui {
class selectColorDialog;
}

class selectColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit selectColorDialog(QWidget *parent = 0);
    ~selectColorDialog();
public slots:
    int setR();
    int setG();
    int setB();

private:
    Ui::selectColorDialog *ui;
};

#endif // SELECTCOLORDIALOG_H
