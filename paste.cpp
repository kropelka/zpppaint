#include "paste.h"
#include<QClipboard>
#include <QMimeData>
#include<QImage>
#include<QVariant>
#include<QPainter>
#include<QApplication>

void Paste::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{
    QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    if(mimeData->hasImage())
    {
        QImage pastedImage = qvariant_cast<QImage>(mimeData->imageData());
        QPainter painter(&image);
        painter.drawImage(currentPoint, pastedImage);
    }
}

Paste::Paste()
{
    name = "Wklej";
    icon = QIcon(":/icons/paste.png");
    singleClick = true;

}
