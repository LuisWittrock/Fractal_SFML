#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Fractal
{
    public:
        Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout);
        VertexArray calcMandelbrot();
    private:
        int mandelbrotEscape(pair<double, double> &RealImg);
        pair<double, double> screenToWorld(int pixelCoordReal, int pixelCoordImg);
        void checkInput();

        VertexArray varray;
        int WINDOW_HEIGHT, WINDOW_WIDTH;
        int bailout;
        double graphXMax = 1, graphXMin = -2.5, graphYMax = 1, graphYMin = -1;
};