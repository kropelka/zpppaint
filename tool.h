#ifndef TOOL_H
#define TOOL_H

#include <QString>
#include <QIcon>
#include<QPoint>

class Tool
{
public:
    QString name;
    QIcon icon;
    Tool();
    virtual void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint);
private:
};

#endif // TOOL_H
