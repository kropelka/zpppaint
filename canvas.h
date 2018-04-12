#ifndef CANVAS_H
#define CANVAS_H
#include<QWidget>
#include<QImage>
#include<QPainter>
#include<QRect>
#include<QPaintEvent>
#include<QPoint>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas(QWidget *parent = 0);
    void loadImage(const QString& filename);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QImage image;
    QPoint lastPoint;
    bool currentlyDrawing;
};

#endif // CANVAS_H
