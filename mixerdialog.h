#ifndef MIXERDIALOG_H
#define MIXERDIALOG_H

#include <QDialog>

namespace Ui {
class MixerDialog;
}

class MixerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MixerDialog(QWidget *parent = 0);
    ~MixerDialog();
public slots:
    int setR();
private:
    Ui::MixerDialog *ui;
};

#endif // MIXERDIALOG_H
