#ifndef GAMMADIALOG_H
#define GAMMADIALOG_H

#include <QDialog>

namespace Ui {
class GammaDialog;
}

class GammaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GammaDialog(QWidget *parent = 0);
    ~GammaDialog();
public slots:
    int setGam();

private:
    Ui::GammaDialog *ui;
};

#endif // GAMMADIALOG_H
