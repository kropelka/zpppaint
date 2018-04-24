#include "canvas.h"
//siema mordy test
Canvas::Canvas(QWidget *parent)
{

}

void Canvas::loadImage(const QString &filename)
{
    image.load(filename);
}

void Canvas::newImage(int width, int height)
{
    QImage newImage(width,height, QImage::Format_RGB32);
    newImage.fill(Qt::white);
    image = newImage;
}

int Canvas::getWidth()
{
    return image.width();
}

int Canvas::getHeight()
{
    return image.height();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    lastPoint = event->pos();
    currentlyDrawing = true;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() && currentlyDrawing)
    {
        QPainter painter(&image);
        painter.drawLine(lastPoint, event->pos());
        //painter.drawPoint(lastPoint);
        update(QRect(lastPoint, event->pos()).normalized());
        lastPoint = event->pos();
        update();  //dzięki temu updatowi nie ma przerw pomiędzy rysowanymi liniami
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->buttons() && currentlyDrawing)
    {
        QPainter painter(&image);
        painter.drawLine(lastPoint, event->pos());
        update(QRect(lastPoint, event->pos()).normalized());
        lastPoint = event->pos();
    }
    currentlyDrawing = false;
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}



