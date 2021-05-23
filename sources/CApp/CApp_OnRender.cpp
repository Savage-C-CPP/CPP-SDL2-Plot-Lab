#include "CApp.h"
#include "CDraw.h"

void CApp::OnRender()
{
    CDraw::DrawCircle(Renderer, Pen.x, Pen.y, pen_r, true); // Ставим жирную точку в текущей позиции пера
    // CDraw::DrawNStar(Renderer, num_of_verts, R, cx, cy);
    SDL_RenderPresent(Renderer);
    SDL_Delay((1.0 / 60) * 250);
}
