#include <SDL2/SDL.h>
using namespace std;

#include <string>

class Window {

    int width, height;
    string title;
    SDL_Window * sdl_window;

    public:
    Window(int width, int height, string title);

    ~ Window();
};