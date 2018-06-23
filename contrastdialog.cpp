#include "contrastdialog.h"
#include "ui_contrastdialog.h"

ContrastDialog::ContrastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContrastDialog)
{
    ui->setupUi(this);
}

ContrastDialog::~ContrastDialog()
{
    delete ui;
}


int ContrastDialog::setK()
{
    return ui->partSlider->value();
}
