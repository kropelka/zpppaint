#include "thresholddialoh.h"
#include "ui_thresholddialoh.h"

ThresholdDialoh::ThresholdDialoh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thresholdDialoh)
{
    ui->setupUi(this);
}

ThresholdDialoh::~ThresholdDialoh()
{
    delete ui;
}


int ThresholdDialoh::setU()
{
    return ui->partSlider->value();
}
