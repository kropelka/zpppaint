#ifndef BRESENHAM_H
#define BRESENHAM_H
#include<functional>

namespace algorithms
{
void drawLineBresenham(int x0, int y0, int x1, int y1, const std::function<void(int, int)>& drawingFunction);
}
#endif // BRESENHAM_H
