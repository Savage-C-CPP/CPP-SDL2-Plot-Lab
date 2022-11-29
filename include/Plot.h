#ifndef _PLOT_H_
#define _PLOT_H_

#include <SDL.h>

class Plot
{
private:
    class Coordinates
    {
    public:
        SDL_Point ox0, ox1, ox0_home, ox1_home;
        SDL_Point oy0, oy1, oy0_home, oy1_home;

        int *x0, *y0;
        double kx, kx_home, ky, ky_home; // Масштаб 1 деления

        void Init(SDL_Point ox0, SDL_Point ox1, SDL_Point oy0, SDL_Point oy1, double kx, double ky)
        {
            this->ox0 = this->ox0_home = ox0;
            this->ox1 = this->ox1_home = ox1;
            this->oy0 = this->oy0_home = oy0;
            this->oy1 = this->oy1_home = oy1;

            this->x0 = &this->oy0.x;
            this->y0 = &this->ox0.y;

            this->kx = kx_home = kx;
            this->ky = ky_home = ky;
        }
        void moveUp(double inc)
        {
            ox0.y += inc;
            ox1.y += inc;
        }
        void moveDown(double dec)
        {
            ox0.y -= dec;
            ox1.y -= dec;
        }
        void moveLeft(double inc)
        {
            oy0.x -= inc;
            oy1.x -= inc;
        }
        void moveRight(double dec)
        {
            oy0.x += dec;
            oy1.x += dec;
        }
        void moveHome()
        {
            ox0 = ox0_home;
            ox1 = ox1_home;
            oy0 = oy0_home;
            oy1 = oy1_home;

            kx = kx_home;
            ky = ky_home;
        }
    };


public:
    Coordinates c;

    Plot() {};
    Plot(SDL_Point ox0, SDL_Point ox1, SDL_Point oy0, SDL_Point oy1, double kx, double ky)
    {
        c.Init(ox0, ox1, oy0, oy1, kx, ky);
    };

    int osx(double x) // Перевод координаты X точки на координату X на окне
    {
        return *c.x0 + c.kx * x;
    }

    int osy(double y) // Перевод координаты Y точки на координату Y на окне
    {
        return *c.y0 - c.ky * y;
    }

    double f(double x)
    {
        // return sin(x);
        return (x * x) / (x + 2);
    }

};
#endif // _PLOT_H_
