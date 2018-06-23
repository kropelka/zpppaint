#ifndef BRIGHTNESSDIALOG_H
#define BRIGHTNESSDIALOG_H

#include <QDialog>

namespace Ui {
class BrightnessDialog;
}

class BrightnessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrightnessDialog(QWidget *parent = 0);
    ~BrightnessDialog();
public slots:
    int setBr();

private:
    Ui::BrightnessDialog *ui;
};

#endif // BRIGHTNESSDIALOG_H
