#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <vector>
#include "NStar.h"

class CApp
{
private:
    int w_w, w_h;
    bool running;
    const char *WindowTitle = "Plot";

    SDL_Window *Window;
    SDL_Surface *Surface;
    SDL_Renderer *Renderer;

public:
    CApp();

    int OnExecute();
    bool OnInit();
    void OnLoop();
    void OnEvent(SDL_Event *);
    void OnRender();
    void OnCleanup();

public:
    SDL_Point Pen;  // Позиция пера
    SDL_Point Dest; // Вершина, к которой движется перо
    std::vector<SDL_Point> traectory; // траектория движения пера
    std::vector<SDL_Point>::iterator traectory_it; // траектория движения пера

    NStar *Star;
};

#endif // _CAPP_H_
