#include "CApp.h"
#include <random>

void CApp::OnSetRandPenColor()
{
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
