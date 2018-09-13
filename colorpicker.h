#ifndef COLORPICKER_H
#define COLORPICKER_H
#include "tool.h"


class ColorPicker : public Tool
{
public:
    void showColorDialog();
    ColorPicker();
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint);
    void updateIcon();
};

#endif // COLORPICKER_H
