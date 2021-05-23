#include "CApp.h"
#include "CDraw.h"

CApp::CApp()
{
    w_w = 700;
    w_h = 700;

    Window = nullptr;
    Surface = nullptr;

    num_of_verts = 5,
    r = 200,
    R = 500,
    a = 360,
    cx = w_w / 2,
    cy = w_h / 2;
    pen_r = 20;

    // TODO: Пользовательский воод где-то здесь
    Star = new NStar(num_of_verts,
                     r,
                     R,
                     a,
                     cx,
                     cy);

    Pen = *Star->begin; // Ставим перо на начало коллекции вершин
    Dest = *Star->it;   // Вершина, куда перо поведёт линию
    OnChangePenTraectory();

    running = true;
}

int CApp::OnExecute()
{
    if (OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while (running)
    {
        while (SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}
