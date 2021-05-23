#ifndef _NSTAR_H_
#define _NSTAR_H_

#include <vector>
#include <SDL.h>
#include <iostream>

// Для N конечной звезды
// Получаем исходные данные от пользователя, вызываем методы, потом инициализируем графику
class NStar
{
public:
    int NumOfVerts;
    std::vector<SDL_Point> *StarVerts; // Вектор вершин звезды
    std::vector<SDL_Point>::iterator begin, it, end;
    NStar(int n, int r, int R, int a, int x, int y)
    {
        int al = a;
        NumOfVerts = n;
        int num_of_points = n * 2 + 1;
        SDL_Point point;
        StarVerts = new std::vector<SDL_Point>();

        for (size_t i = 1; i < num_of_points + 1; i++)
        {
            if (!(i % 2))
            {
                point.x = x + r / 2 * cos(al * M_PI / 180);
                point.y = y - r / 2 * sin(al * M_PI / 180);
                StarVerts->push_back(point);
            }
            else
            {
                point.x = x + R * cos(al * M_PI / 180);
                point.y = y - R * sin(al * M_PI / 180);
                StarVerts->push_back(point);
            }
            al = al + 180 / n;
        }
        point = StarVerts->front();
        StarVerts->push_back(point);
        begin = StarVerts->begin(); // Начальная вершина (для начала цикла отрисовки с начала)
        it = StarVerts->begin();    // Очередная вершина, куда будет двигаться перо
        it++;                       // Ставим её следующей от начала
        end = std::prev(StarVerts->end());     // Конечная вершина (для проверки окончания цикла)
    };
    ~NStar()
    {
        delete StarVerts;
    }

    void PrintVerts()
    {
        std::cout << "Verts\n";
        std::vector<SDL_Point>::iterator i;
        for (i = StarVerts->begin(); i != StarVerts->end(); ++i)
        {
            SDL_Point p = *i;
            std::cout << "Vert(" << p.x << ", " << p.y << ")\n";
        }
    }
};

#endif // _NSTAR_H_
