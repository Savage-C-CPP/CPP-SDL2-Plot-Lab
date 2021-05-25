#include "CDraw.h"
#include <cmath>

/* Function that returns -1,0,1 depending on whether x */
/* is <0, =0, >0 respectively */
#define sign(x) ((x > 0) ? 1 : ((x < 0) ? -1 : 0))

void CDraw::DrawLine(SDL_Renderer *renderer, int x0, int y0, int x1, int y1, int radius)
{

    // Print prompt
    // printPrompt(x0, y0, x1, y1);

    int signx = sign(x1 - x0);
    int signy = sign(y1 - y0);
    int dy = y1 - y0;
    int dx = x1 - x0;
    bool hasExchanged = false;

    // Judge the growing direction
    // Slope K : abs(K) > 1
    int t;
    if (abs(dy) > abs(dx))
    {
        t = dx, dx = dy, dy = t;
        hasExchanged = true;
    }

    // Initial bias
    int e = 2 * dy - dx;

    // Calculate each points' position and paint on canvas
    int x = x0;
    int y = y0;

    // Paint ( dx + 1 ) times
    for (int i = 0; i <= dx; ++i)
    {
        // SDL_RenderDrawPoint(renderer, x, y);
        CDraw::DrawCircle(renderer, x, y, radius, true);

        // abs(K) > 1
        // Y dirextion self increment with signy
        // X direction depend on the value of e
        if (hasExchanged)
        {
            y = y + signy;
            if (e >= 0)
            {
                x = x + 1;

                // Update e
                e = e + 2 * dy - 2 * dx;
            }
            else
            {
                e = e + 2 * dy;
            }
        }
        else
        {
            x = x + signx;
            if (e >= 0)
            {
                y = y + 1;

                // Update e
                e = e + 2 * dy - 2 * dx;
            }
            else
            {
                e = e + 2 * dy;
            }
        }
    }
}
