#include "CApp.h"
#include "CDraw.h"

CApp::CApp()
{
    w_w = 700;
    w_h = 700;

    Window = nullptr;
    Surface = nullptr;
                                                // Minimum      Maximum
    std::cout << "Введите размер экрана:";
    std::cout << "\n\twidth: ";                 // 100          1366
    std::cin >> w_w;
    std::cout << "\n\theight: ";
    std::cin >> w_h;                            // 100          768
    std::cout << "\nВведите параметры звезды:";
    std::cout << "\n\tКоличество вершин: ";
    std::cin >> num_of_verts;                   // 3            inf
    std::cout << "\n\tВнешний радиус: ";
    std::cin >> R;                              // ?            ?
    std::cout << "\n\tВнутренний радиус: ";
    std::cin >> r;                              // ?            ?
    std::cout << "\n\tУгол наклона alpha: ";
    std::cin >> a;                              // -inf         inf
    std::cout << "\nВведите радиус пера: ";
    std::cin >> pen_r;

    cx = w_w / 2; // Координаты центра пусть будудт в центре окна
    cy = w_h / 2;

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
