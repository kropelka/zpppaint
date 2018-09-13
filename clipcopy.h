#ifndef CLIPCOPY_H
#define CLIPCOPY_H
#include "tool.h"

class ClipCopy : public Tool
{
public:
    ClipCopy();
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint) override;
};

#endif // CLIPCOPY_H
