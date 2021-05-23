#include "CDraw.h"
#include <cmath>

void CDraw::DrawNStar(SDL_Renderer *renderer, int n, double rad, int x, int y)
{
    double a = 0, b = 3.14159265358979323846 / n, k = 0.3;
    int x1 = (x + (int)(rad * cos(a))), x2, y1 = (y + (int)(rad * sin(a))), y2;

    for (int i = 0; i < n; i++)
    {
        a = a + b;
        y2 = (y + (int)(k * rad * sin(a)));
        x2 = (x + (int)(k * rad * cos(a)));
        a = a + b;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        x1 = (x + (int)(rad * cos(a)));
        y1 = (y + (int)(rad * sin(a)));
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
};
