#include "brightnessdialog.h"
#include "ui_brightnessdialog.h"

BrightnessDialog::BrightnessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessDialog)
{
    ui->setupUi(this);
}

BrightnessDialog::~BrightnessDialog()
{
    delete ui;
}

int BrightnessDialog::setBr()
{
    return ui->partSlider->value();
}
