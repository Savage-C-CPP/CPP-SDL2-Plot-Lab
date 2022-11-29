#include "CApp.h"
#include <iostream>

CApp::CApp()
{
    Window = nullptr;
    Surface = nullptr;

    // Пользователь вводит (w_w, w_h), kx, ky, lide_radius

    w_w = 800;
    w_h = 600;
    line_radius = 2;

    int kx, ky; 
    kx = 25, ky = 25;

    // Задаём координаты центра координат, коэффициэнты масштабирования
    plot.c.Init({0, w_h - 50}, {w_w, w_h - 50}, {50, 0}, {50, w_h}, kx, ky);

    solve_f();

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
