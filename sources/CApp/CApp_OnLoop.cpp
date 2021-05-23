#include "CDraw.h"
#include "CApp.h"
#include <random>

void CApp::OnLoop()
{
    // TODO: Прокускать 2 вершины через алгоритм брезенхема, получать тракеторию пера
    // Двигать перо по точкам из траектории, пока траектория не кончится
    // Когда траектория кончилась, брать текущее положение пера и следующую вершину, и так пока вершина не есть последняя
    // Когда последняя, всё повторяется с новым цветом

    if (Star->it != Star->end) // Пока не дошли до отца
    {
        if (Pen.x == Dest.x && Dest.y == Pen.y) // Если перо дошло до очередной вершины
        {
            ++Star->it;       // Двигаем цель
            Dest = *Star->it; // Берём следующую вершину
            // Решаем траекторию движения пера
            traectory = CDraw::GetAllPointsBrezenham(Pen.x, Pen.y, Dest.x, Dest.y);
            traectory_it = traectory.begin();
            traectory_it++;
            Dest = *std::prev(traectory.end());
        }
        else
        {
            Pen.x = traectory_it->x;
            Pen.y = traectory_it->y;
            ++traectory_it;
        }
    }
    else // Если дошли до последней вершины
    {
        // ставим всё в исходные позиции
        Star->it = Star->begin;
        Dest = *Star->it;

        // Решаем траекторию движения пера
        traectory = CDraw::GetAllPointsBrezenham(Pen.x, Pen.y, Dest.x, Dest.y);
        traectory_it = traectory.begin();
        traectory_it++;
        Dest = *std::prev(traectory.end());

        // меняем цвет пера на рандомный
        std::random_device seeder;
        std::ranlux48 gen(seeder());
        std::uniform_int_distribution<int> uniform_0_255(0, 255);

        int r, g, b, a = 255;
        r = uniform_0_255(gen);
        g = uniform_0_255(gen);
        b = uniform_0_255(gen);

        SDL_SetRenderDrawColor(Renderer, r, g, b, a);
    }
}
