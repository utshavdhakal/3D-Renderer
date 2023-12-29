#include "window.h"
using namespace std;

Window::Window(int width, int height, string title) {
    this->width = width;
    this->height = height;
    this->title = title;
    
    this->sdl_window = NULL;

    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
        const char * error_message = SDL_GetError();
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            error_message,
            NULL
        );
        return;
    }

    this->sdl_window = SDL_CreateWindow(
        this->title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->width,
        this->height, SDL_WINDOW_SHOWN
    );

    if (this->sdl_window == NULL) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            SDL_GetError(),
            NULL
        );
    }
}

Window :: ~ Window() {
    SDL_DestroyWindow(this->sdl_window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}