#include "Fractal.hpp"

Fractal::Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout)
{
    this->WINDOW_HEIGHT = WINDOW_HEIGHT;
    this->WINDOW_WIDTH = WINDOW_WIDTH;
    this->bailout = bailout;
}
pair<double, double> Fractal::screenToWorld(int pixelCoordReal, int pixelCoordImg) //translates pixel coordinate to a coordinate of a complex number (a*bi)
{
    double ImgCoord = (double)pixelCoordImg*((graphYMax-graphYMin)/(double)WINDOW_HEIGHT) + graphYMin;
    double RealCoord = (double)pixelCoordReal*((graphXMax-graphXMin)/(double)WINDOW_WIDTH) + graphXMin;
    return make_pair(RealCoord, ImgCoord);
}
VertexArray Fractal::calcMandelbrot()
{
    varray.clear();
    Vertex vertex;

    for(int img = 0; img<WINDOW_HEIGHT; img++)
    {
        for(int real = 0; real<WINDOW_WIDTH; real++)
        {
            vertex.position = Vector2f(real, img);
            pair<double,double> RealImgPair = screenToWorld(real, img);

            int escape = mandelbrotEscape(RealImgPair);

            if(escape == bailout) vertex.color = Color::Black;
            else vertex.color = Color::White;

            varray.append(vertex);
        }
    }
    return varray;
}
int Fractal::mandelbrotEscape(pair<double, double> &RealImgPair)
{
    double realC = RealImgPair.first;
    double imgC = RealImgPair.second;
    double Zreal = 0.0;
    double Zimg = 0.0;
    int iteration = 0;

    do
    {
        double tmpReal = (Zreal*Zreal)-(Zimg*Zimg)+realC;
        Zimg = 2*Zreal*Zimg + imgC;
        Zreal = tmpReal;
        iteration++;
    }
    while((Zreal*Zreal + Zimg*Zimg) <= 4 && iteration < bailout);

    return iteration;
}