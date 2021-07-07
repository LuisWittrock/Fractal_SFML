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
        void checkKeys();
        void draw();
        void update();

        int bailout = 50;
        int WINDOW_WIDTH = 1000;
        int WINDOW_HEIGHT = 720;
        RenderWindow window;
        Event event;
        Fractal fractal;
};