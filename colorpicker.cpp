#include "colorpicker.h"
#include<QColor>
#include<QColorDialog>
#include<iostream>
ColorPicker::ColorPicker()
{

}

void ColorPicker::showColorDialog()
{
    QColorDialog *cd = new QColorDialog;
    QColor newColor = cd->getColor(color);
    if(newColor.isValid())
    {
        color = newColor;
    }
}

void ColorPicker::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    std::cerr << "Rysowanie wyborem koloru?!";

}

void ColorPicker::updateIcon()
{

}
