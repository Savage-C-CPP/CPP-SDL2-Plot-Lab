#include "CApp.h"

void CApp::OnPenTick()
{
    if (Star->it != Star->end) // Пока не дошли до отца
    {
        if (Pen.x == Dest.x && Dest.y == Pen.y) // Если перо дошло до очередной вершины
        {
            ++Star->it;       // Двигаем цель
            Dest = *Star->it; // Берём следующую вершину
            OnChangePenTraectory();
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
        OnChangePenTraectory();
        OnSetRandPenColor();
    }
}
