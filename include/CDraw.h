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
    static void DrawNStar(SDL_Renderer *renderer, int n, double radius, int x, int y);
    static void DrawGrid(SDL_Renderer *renderer, int x_start, int y_start, int x_end, int y_end, int cell_width, int cell_height);

    // Return all the points a line going thorug. Uses Brezenham algorithm
    // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    static std::vector<SDL_Point> BresenhamLineVector(int x0, int y0, int x1, int y1);
};

#endif // _CDRAW_H_
