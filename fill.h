#ifndef FILL_H
#define FILL_H
#include "tool.h"


class Fill : public Tool
{
public:
    Fill();
     void draw(QImage &image, const QPoint& lastPoint, const QPoint& currentPoint);
private:
};

#endif // FILL_H
