#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT)
    {
        running = false;
    }
    if (Event->type == SDL_KEYDOWN && Event->key.keysym.sym == SDLK_ESCAPE)
    {
        running = false;
    }
}
