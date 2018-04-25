#ifndef BRUSH_H
#define BRUSH_H
#include "tool.h"

class Brush : public Tool
{
public:
    Brush();
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint) override;
};


#endif // BRUSH_H
