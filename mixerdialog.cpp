#include "mixerdialog.h"
#include "ui_mixerdialog.h"

MixerDialog::MixerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MixerDialog)
{
    ui->setupUi(this);
}

MixerDialog::~MixerDialog()
{
    delete ui;
}

void MixerDialog::on_buttonBox_accepted()
{

}
