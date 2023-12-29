#include "window.h"
using namespace std;

class Renderer {
    bool running;
    Window * window;

    public:
    Renderer() {
        this->running = true;
    }

    void create_window(int width, int height, string title) {
        this->window = new Window(width, height, title);
    }

    bool is_running() {
        return this->running;
    }

    void set_running(bool running) {
        this->running = running;
    }
};

int main() {

    Renderer renderer;
    renderer.create_window(500, 400, "3D Renderer");

    /* Event Loop */
    SDL_Event event;
    while(renderer.is_running()) {
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        renderer.set_running(false);
                    }
                    continue;

                case SDL_QUIT:
                    renderer.set_running(false);
                    continue;
            }
        }
    }

    return 0;
}