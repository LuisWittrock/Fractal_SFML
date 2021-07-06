#include "Fractal.hpp"

Fractal::Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout)
{
    this->WINDOW_HEIGHT = WINDOW_HEIGHT;
    this->WINDOW_WIDTH = WINDOW_WIDTH;
    this->bailout = bailout;
}
pair<double, double> Fractal::screenToWorld(int pixelCoordReal, int pixelCoordImg) //translates pixel coordinate to a coordinate of a complex number (a*bi)
{
    double RealCoord = (double)pixelCoordReal*((graphYMax-graphYMin)/(double)WINDOW_HEIGHT) + graphYMin;
    double ImgCoord = (double)pixelCoordImg*((graphXMax-graphXMin)/(double)WINDOW_WIDTH) + graphXMin;
    return make_pair(RealCoord, ImgCoord);
}
VertexArray Fractal::calcMandelbrot()
{

}
int Fractal::mandelbrotEscape(double real, double imaginary)
{

}