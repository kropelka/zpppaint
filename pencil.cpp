#include "pencil.h"
#include <QPainter>

Pencil::Pencil()
{

}

void Pencil::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    QPainter painter(&image);
    painter.drawLine(lastPoint, currentPoint);
}
