#pragma once
#include <SFML/Graphics.hpp>
#include <array>

using namespace sf;
using namespace std;

class Fractal
{
    public:
        Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout);
        VertexArray calcMandelbrot();
    private:
        VertexArray varray;
        int WINDOW_HEIGHT, WINDOW_WIDTH;
        int bailout;
        double graphXMax = 1, graphXMin = -2, graphYMax = 1, graphYMin = -1;
        
        void colorMixer(int escape, sf::Vertex &vertex);
        int mandelbrotEscape(pair<double, double> &RealImg);
        std::pair<double, double> screenToWorld(int pixelCoordReal, int pixelCoordImg);
};