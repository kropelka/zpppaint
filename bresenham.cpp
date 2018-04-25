#include "bresenham.h"
#include <algorithm>

namespace algorithms
{

void drawLineLow(int x0, int y0, int x1, int y1, const std::function<void (int, int)> &drawingFunction)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yinc = 1;
    if(dy < 0)
    {
        yinc = -1;
        dy = -dy;
    };
    int D = 2 * dy - dx;
    int y = y0;

    for(int x=x0; x <= x1; ++x)
    {
        drawingFunction(x, y);
        if(D>0)
        {
            y += yinc;
            D -= 2 * dx;
        };
        D += 2*dy;
    }
}

void drawLineHigh(int x0, int y0, int x1, int y1, const std::function<void (int, int)> &drawingFunction)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xinc = 1;
    if(dx < 0)
    {
        xinc = -1;
        dx = -dx;
    };
    int D = 2 * dx - dy;
    int x = x0;

    for(int y=y0; y <= y1; ++y)
    {
        drawingFunction(x, y);
        if(D>0)
        {
            x += xinc;
            D -= 2 * dy;
        };
        D += 2*dx;
    }
}



void drawLineBresenham(int x0, int y0, int x1, int y1, const std::function<void (int, int)> &drawingFunction)
{
    if(x1==x0)  // linia pionowa nie obsługiwana przez Bressenhama
    {
        for(int y = std::min(y0, y1); y <= std::max(y0, y1); ++y)
        {
           drawingFunction(x0, y);
        }
    }
    else
    {
        if(abs(y1-y0) < abs(x1-x0))
        {
            if(x0>x1)
            {
                drawLineLow(x1, y1, x0, y0, drawingFunction);
            }
            else
            {
                drawLineLow(x0, y0, x1, y1, drawingFunction);
            }
        }
        else
            if(y0>y1)
            {
                drawLineHigh(x1, y1, x0, y0, drawingFunction);
            }
            else
            {
                drawLineHigh(x0, y0, x1, y1, drawingFunction);
            }

    };
}

}
