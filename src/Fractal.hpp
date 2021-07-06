#pragma once
#include <SFML/Graphics.hpp>
#include "Application.hpp"
using namespace sf;

class Fractal
{
    public:
        Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout);
        VertexArray calcMandelbrot();
    private:
        int mandelbrotEscape(double real, double imaginary);
        double screenToWorld();
        void checkInput();

        VertexArray varray;
        int WINDOW_HEIGHT, WINDOW_WIDTH;
        int bailout;
        double graphXMax = 2, graphXMin = -0.5, graphYMax = 1, graphYMin = -1;
};