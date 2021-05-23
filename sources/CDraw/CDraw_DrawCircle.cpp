#include "CDraw.h"

void CDraw::DrawCircle(SDL_Renderer *renderer, int centreX, int centreY, int radius, bool fill)
{
    const int diameter = (radius * 2);

    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        // If fill flag is on, the circle will be filled out
        if (fill)
        {
            SDL_RenderDrawLine(renderer, centreX - x, centreY - y, centreX + x, centreY - y);
            SDL_RenderDrawLine(renderer, centreX - y, centreY + x, centreX + y, centreY + x);
            SDL_RenderDrawLine(renderer, centreX - y, centreY - x, centreX + y, centreY - x);
            SDL_RenderDrawLine(renderer, centreX - x, centreY + y, centreX + x, centreY + y);
        }

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}
