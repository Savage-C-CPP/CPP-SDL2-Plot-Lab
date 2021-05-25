#include "CDraw.h"

void CDraw::DrawGrid(SDL_Renderer *renderer, int x_start, int y_start, int x_end, int y_end, int cell_width, int cell_height)
{
    // Horizontal linses
    for (int x = x_start; x < x_end; x += cell_width)
    {
        SDL_RenderDrawLine(renderer, x, y_start, x, y_end);
    }
    // Vertical lines
    for (int y = y_start; y < y_end; y += cell_height)
    {
        SDL_RenderDrawLine(renderer, x_start, y, x_end, y);
    }
}
