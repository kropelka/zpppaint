#include "gammadialog.h"
#include "ui_gammadialog.h"

GammaDialog::GammaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GammaDialog)
{
    ui->setupUi(this);
}

GammaDialog::~GammaDialog()
{
    delete ui;
}

int GammaDialog::setGam()
{
    return ui->partSlider->value();
}
