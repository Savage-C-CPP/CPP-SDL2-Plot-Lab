#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <vector>
#include "NStar.h"

class CApp
{
private:
    int w_w = 700,
        w_h = 700;

    bool running;
    const char *WindowTitle = "Star";

    // Пользователь вводит
    int num_of_verts = 5, // Количество вершин
        r = 200,          // внутренний радиус звезды
        R = 200,          // внешний радиус звезды
        a = 20,           // Угол наклона звезды на плоскости
        cx = w_w / 2,     // центро звезды x
        cy = w_h / 2,     // центро звезды y
        pen_r = 20;       // радиус пера

    SDL_Window *Window;
    SDL_Surface *Surface;
    SDL_Renderer *Renderer;

public: // Цикл программы
    CApp();

    int OnExecute();
    bool OnInit();
    void OnLoop();
    void OnEvent(SDL_Event *);
    void OnRender();
    void OnCleanup();

public:                                            // Логика отрисовки звезды
    SDL_Point Pen;                                 // Позиция пера
    SDL_Point Dest;                                // Вершина, к которой движется перо
    std::vector<SDL_Point> traectory;              // траектория движения пера
    std::vector<SDL_Point>::iterator traectory_it; // траектория движения пера

    NStar *Star;

    void OnSetRandPenColor();
    void OnChangePenTraectory();
    void OnPenTick();
};

#endif // _CAPP_H_
