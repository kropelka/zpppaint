#include "fill.h"
#include <queue>
#include <stack>
Fill::Fill()
{
    singleClick = true;
    fullScreenOperation = true;
    name = "Wypełnienie";
    icon = QIcon(":/icons/bucket.png");
}



void Fill::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    int height = image.height();
    int width = image.width();


    std::stack<QPoint> pointsToColor;

    pointsToColor.push(currentPoint);
    int x0 = currentPoint.x();
    int y0 = currentPoint.y();
    QColor targetColor = image.pixelColor(x0, y0);

    while(!pointsToColor.empty())
    {
        QPoint p = pointsToColor.top();
        pointsToColor.pop();
        if(p.ry() < 0 || p.ry() > height -1 || p.rx() < 0 || p.rx() > width - 1)
        {
            continue;
        }
        QColor pointColor = image.pixelColor(p.rx(), p.ry());
        if(pointColor == targetColor)
        {
            image.setPixelColor(p, color);
            pointsToColor.push(QPoint(p.rx() + 1, p.ry()));
            pointsToColor.push(QPoint(p.rx() - 1, p.ry()));
            pointsToColor.push(QPoint(p.rx(), p.ry() + 1));
            pointsToColor.push(QPoint(p.rx(), p.ry() - 1));
        }

    }
}
