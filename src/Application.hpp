#pragma once
#include <SFML/Graphics.hpp>
#include "Fractal.hpp"

using namespace sf;

class Application
{
    public:
        Application();
        void start();
        RenderWindow window;
    private:
        void checkKeys();
        void draw();
        void update();

        int bailout = 50;
        int WINDOW_WIDTH = 1280;
        int WINDOW_HEIGHT = 720;
        
        Event event;
        Fractal fractal;
};