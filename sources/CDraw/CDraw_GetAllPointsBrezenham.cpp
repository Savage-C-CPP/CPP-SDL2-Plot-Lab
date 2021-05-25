#include "CDraw.h"
#include <vector>
#include <cmath>

/* Function that returns -1,0,1 depending on whether x */
/* is <0, =0, >0 respectively */
#define sign(x) ((x > 0) ? 1 : ((x < 0) ? -1 : 0))

std::vector<SDL_Point> CDraw::BresenhamLineVector(int x0, int y0, int x1, int y1)
{
    std::vector<SDL_Point> points;
    int dx, dy, x, y, d, s1, s2, swap = 0, temp;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    s1 = sign(x1 - x0);
    s2 = sign(y1 - y0);

    /* Check if dx or dy has a greater range */
    /* if dy has a greater range than dx swap dx and dy */
    if (dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }

    /* Set the initial decision parameter and the initial point */
    d = 2 * dy - dx;
    x = x0;
    y = y0;

    int i;
    for (i = 1; i <= dx; i++)
    {
        SDL_Point p;
        p.x = x;
        p.y = y;
        points.push_back(p);

        while (d >= 0)
        {
            if (swap)
                x = x + s1;
            else
                y = y + s2;
            d = d - 2 * dx;
        }
        if (swap)
            y = y + s2;
        else
            x = x + s1;
        d = d + 2 * dy;
    }
    return points;
};
