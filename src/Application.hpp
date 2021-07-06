#pragma once
#include <SFML/Graphics.hpp>
#include "Fractal.hpp"

using namespace sf;

class Application
{
    public:
        Application();
        void start();
    private:
        void draw();
        void update();

        int bailout = 500;
        int WINDOW_WIDTH = 1280;
        int WINDOW_HEIGHT = 720;
        RenderWindow window;
        Event event;
        Fractal fractal;
};