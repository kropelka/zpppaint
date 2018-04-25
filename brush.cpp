#include "brush.h"
#include <QPainter>
#include "bresenham.h"
Brush::Brush()
{

}


void Brush::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    float eps = 10e-6;
    QPainter painter(&image);
    int x0 = currentPoint.x();
    int y0 = currentPoint.y();
    int x1 = lastPoint.x();
    int y1 = lastPoint.y();
    algorithms::drawLineBresenham(x0, y0, x1, y1, [&painter] (int x, int y) {
        painter.drawEllipse(x, y, 1, 1);
    } );
}
