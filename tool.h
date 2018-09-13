#ifndef TOOL_H
#define TOOL_H

#include <QString>
#include <QIcon>
#include<QPoint>
#include<QColor>

class Tool
{
public:

    QString name;
    QIcon icon;
    QColor color;

    Tool();
    virtual void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint);
    bool isSingleClick();
    bool singleClick;
    bool fullScreenOperation;
    bool isFullSCreenOperation();
    QPoint startingPoint;
    virtual void updateColor();
private:

};

#endif // TOOL_H
