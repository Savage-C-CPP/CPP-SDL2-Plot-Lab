#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT)
    {
        running = false;
    }
    if (Event->type == SDL_KEYDOWN)
        switch (Event->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_w:
            plot.c.moveUp(plot.c.ky);
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_s:
            plot.c.moveDown(plot.c.ky);
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_a:
            plot.c.moveRight(plot.c.kx);
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_d:
            plot.c.moveLeft(plot.c.kx);
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_0:
        case SDLK_KP_0:
            plot.c.moveHome();
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_PLUS:
        case SDLK_KP_PLUS:
            plot.c.kx += 1;
            plot.c.ky += 1;
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_MINUS:
        case SDLK_KP_MINUS:
            if (plot.c.kx - 1 > 0 && plot.c.ky - 1 > 0)
            {
                plot.c.kx -= 1;
                plot.c.ky -= 1;
            }
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_UP:
            plot.c.ky += 1;
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_DOWN:
            if (plot.c.ky - 1 > 0)
                plot.c.ky -= 1;
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_RIGHT:
            plot.c.kx += 1;
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;

        case SDLK_LEFT:
            if (plot.c.kx - 1 > 0)
                plot.c.kx -= 1;
            SDL_SetRenderDrawColor(Renderer, 64, 92, 177, 0xFF);
            SDL_RenderClear(Renderer);
            solve_f();
            break;
        }
}
