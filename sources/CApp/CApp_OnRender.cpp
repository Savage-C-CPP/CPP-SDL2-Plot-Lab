#include "CApp.h"
#include "CDraw.h"

void CApp::OnRender()
{
    CDraw::DrawCircle(Renderer, Pen.x, Pen.y, 5, true); // Ставим жирную точку в текущей позиции пера
    // CDraw::DrawLine(Renderer, Pen.x, Pen.y, Dest.x, Dest.y, 10);
    // CDraw::DrawNStar(Renderer, 5, 100, 350, 350);
    SDL_RenderPresent(Renderer);
    SDL_Delay((1.0 / 60) * 400);
}
