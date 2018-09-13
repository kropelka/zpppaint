#include "clipcopy.h"
#include<QRect>
#include<QApplication>
#include<QClipboard>

ClipCopy::ClipCopy()
{
    name = "Kopiuj do schowka";
    icon = QIcon(":/icons/copy.png");
}

void ClipCopy::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    const QPoint &p1 = currentPoint;
    const QPoint &p2 = startingPoint;
    int x = std::min(p1.x(), p2.x());
    int y = std::min(p1.y(), p2.y());
    int w = std::abs(p1.x() - p2.x());
    int h = std::abs(p1.y() - p2.y());

    QRect rect(x, y, w, h);
    QImage imageToCopy = image.copy(rect);
    if(!image.isNull())
    {
        QApplication::clipboard()->setImage(imageToCopy, QClipboard::Clipboard);
    }
}
