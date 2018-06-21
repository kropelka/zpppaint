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

int MixerDialog::setR()
{
   return ui->redSlider->value();
}
