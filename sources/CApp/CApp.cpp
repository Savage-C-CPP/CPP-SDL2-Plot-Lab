#include "CApp.h"
#include "CDraw.h"

CApp::CApp()
{
    w_w = 700;
    w_h = 700;

    Window = nullptr;
    Surface = nullptr;

    int n = 5,
        r = 200,
        R = 200,
        a = 0,
        x = w_w / 2,
        y = w_h / 2;
    // TODO: Пользовательский воод где-то здесь
    Star = new NStar(n, r, R, a, x, y);
    Star->PrintVerts();
    Pen = *Star->begin;                             // Ставим перо на начало коллекции вершин
    Dest = *Star->it;                               // Вершина, куда перо поведёт линию
    traectory = CDraw::GetAllPointsBrezenham(Pen.x, // Задаём траекторию
                                             Pen.y,
                                             Dest.x,
                                             Dest.y);
    traectory_it = traectory.begin();
    traectory_it++;
    Dest = *std::prev(traectory.end());
    std::cout << "Start: (" << Pen.x << ", " << Pen.y << ") Dest: (" << Dest.x << ", " << Dest.y << ")\n";
    std::cout << "Traectory:\n";
    for (auto it = traectory_it; it != traectory.end(); ++it)
        std::cout << "(" << it->x << ", " << it->y << ")\n";
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
