#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surface);
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}
