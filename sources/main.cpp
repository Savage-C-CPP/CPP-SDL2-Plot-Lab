#define SDL_MAIN_HANDLED
#include "CApp.h"

int main(int argc, char **argv)
{
    CApp app;
    exit(app.OnExecute());
}
