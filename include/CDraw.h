#ifndef _CDRAW_H_
#define _CDRAW_H_

#include <SDL.h>
#include <vector>

class CDraw
{

public:
    // https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    static void DrawCircle(SDL_Renderer *renderer, int centreX, int centreY, int radius, bool fill);
    static void DrawLine(SDL_Renderer *renderer, int x0, int y0, int x1, int y1, int line_radius);
    static std::vector<SDL_Point> GetAllPointsBrezenham(int x0, int y0, int x1, int y1);
    static void DrawNStar(SDL_Renderer *renderer, int n, double radius, int x, int y);
};

#endif // _CDRAW_H_
