#include "selectcolordialog.h"
#include "ui_selectcolordialog.h"

selectColorDialog::selectColorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectColorDialog)
{
    ui->setupUi(this);
}

selectColorDialog::~selectColorDialog()
{
    delete ui;
}

int selectColorDialog::setR()
{
   return ui->redSlider->value();
}

int selectColorDialog::setG()
{
   return ui->greenSlider->value();
}

int selectColorDialog::setB()
{
   return ui->blueSlider->value();
}

