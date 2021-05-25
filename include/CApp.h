#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <vector>
#include "CDraw.h"
#include "Plot.h"

class CApp
{
private:
    int w_w = 700,
        w_h = 700;

    bool running;
    const char *WindowTitle = "Plot";

    SDL_Window *Window;
    SDL_Surface *Surface;
    SDL_Renderer *Renderer;

public: // Цикл программы
    CApp();

    int OnExecute();           // Запускает инициализацию, если успешно, запускает цикл программы, где слушаются и обрабатываются события, отрабатывается логика и отрисовывается на экран
    bool OnInit();             // Инициализация компонентов Window, Surface, Renderer
    void OnLoop();             // Запускает процедуру изменения состояния и положения рисующего компонента, задаются вершины и прочее
    void OnEvent(SDL_Event *); // Обработка событий (нажатие esc для выхода)
    void OnRender();           // Рисует кадр отрисовку осей, графика
    void OnCleanup();          // Освобождение ресурсов при завершении программы

private: // Логика отрисовки графика
    std::vector<SDL_Point> points;
    std::vector<SDL_Point>::iterator it_fx;

    Plot plot; // Объект класса с логикой плота

    int line_radius = 2; // Толщина линии графика

    void DrawFunction()
    {
        SDL_Point prev;
        prev = *points.begin();
        for (const auto point : points)
        {
            CDraw::DrawLine(Renderer, prev.x, prev.y, point.x, point.y, line_radius);
            prev = point;
        }
    }

    void solve_f() // Расчёт функции на всём отрезке OX
    {
        points.clear(); // Удаляем старые
        double x, h, xmin, xmax;
        h = 1 / plot.c.kx;
        xmin = (-(*plot.c.x0)) / plot.c.kx;
        xmax = (w_w - (*plot.c.x0)) / plot.c.kx;
        for (x = xmin; x <= xmax; x += h)
        {
            Point(x, plot.f(x));
        }
    }

    void Point(double x, double y) // Переводим координаты, сохраняем
    {
        int xe, ye;
        xe = plot.osx(x);
        ye = plot.osy(y);
        if (xe >= 0 && xe < w_w && ye >= 0 && ye < w_h)
            points.push_back({xe, ye});
    }
};

#endif // _CAPP_H_
