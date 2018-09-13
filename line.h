#ifndef LINE_H
#define LINE_H
#include "tool.h"

class Line : public Tool
{
public:
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint) override;
    Line();
};

#endif // LINE_H
