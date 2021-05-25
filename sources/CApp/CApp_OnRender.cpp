#include "CApp.h"
#include "CDraw.h"

void CApp::OnRender()
{
    //  Отрисовка сетки
    SDL_SetRenderDrawColor(Renderer, 152, 174, 221, 0xFF);
    CDraw::DrawGrid(Renderer, 0, 0, w_w, w_h, plot.c.kx, plot.c.ky);

    // Отрисовка осей абсцис и ординат
    SDL_SetRenderDrawColor(Renderer, 228, 234, 246, 0xFF);
    CDraw::DrawLine(Renderer, plot.c.ox0.x, plot.c.ox0.y, plot.c.ox1.x, plot.c.ox1.y, 2);
    CDraw::DrawLine(Renderer, plot.c.oy0.x, plot.c.oy0.y, plot.c.oy1.x, plot.c.oy1.y, 2);

    // Отрисовка графика функции
    DrawFunction();
    SDL_RenderPresent(Renderer);
    SDL_Delay((1.0 / 60) * 1000);
}
