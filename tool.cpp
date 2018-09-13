#include "tool.h"
#include <QColorDialog>



Tool::Tool()
{

}

void Tool::draw(QImage &image, const QPoint &lastPoint, const QPoint &currentPoint)
{

}

void Tool::updateColor()
{

}

bool Tool::isSingleClick()
{
    return singleClick;
}

bool Tool::isFullSCreenOperation()
{
    return fullScreenOperation;
}
