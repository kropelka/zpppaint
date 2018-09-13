#include "line.h"
#include<QPainter>

void Line::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    QPainter painter(&image);
    painter.setPen(color);
    painter.drawLine(startingPoint, currentPoint);
}

Line::Line()
{
    singleClick = true;
    fullScreenOperation = true;
    name = "Linia";
    icon = QIcon(":/icons/line.png");
}
