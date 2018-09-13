#ifndef PASTE_H
#define PASTE_H
#include "tool.h"

class Paste : public Tool
{
public:
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint) override;
    Paste();
};

#endif // PASTE_H
