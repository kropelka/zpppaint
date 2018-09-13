#ifndef PENCIL_H
#define PENCIL_H
#include "tool.h"


class Pencil : public Tool
{
public:
    Pencil();
    void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint) override;

};

#endif // PENCIL_H
