#include "pencil.h"
#include <QPainter>

Pencil::Pencil()
{
    singleClick = false;
    fullScreenOperation = false;
    name = "Ołówek";
    icon = QIcon(":/icons/pencil.png");
}

void Pencil::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    QPainter painter(&image);
    painter.setPen(color);
    painter.drawLine(lastPoint, currentPoint);
}
