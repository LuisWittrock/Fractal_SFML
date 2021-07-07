#include "Fractal.hpp"

Fractal::Fractal(int WINDOW_HEIGHT, int WINDOW_WIDTH, int bailout)
{
    this->WINDOW_HEIGHT = WINDOW_HEIGHT;
    this->WINDOW_WIDTH = WINDOW_WIDTH;
    this->bailout = bailout;
}

std::pair<double, double> Fractal::screenToWorld(int pixelCoordReal, int pixelCoordImg) //translates pixel coordinate to a coordinate of a complex number (a*bi)
{
    double ImgCoord = (double)pixelCoordImg*((graphYMax-graphYMin)/(double)WINDOW_HEIGHT) + graphYMin;
    double RealCoord = (double)pixelCoordReal*((graphXMax-graphXMin)/(double)WINDOW_WIDTH) + graphXMin;
    return make_pair(RealCoord, ImgCoord);
}

void Fractal::colorMixer(int escape, sf::Vertex &vertex)
{
    int rgb[17][3] = {{66,30,15}, {25,7,26}, {9,1,47}, {4,4,73}, {0,7,100}, {134,181,229}, {211,236,248}, {248,201,95}, {255,170,0}, {204,128,0}, {153,87,0}, {153,87,0}, {106,52,4}, {205,133,0}, {129,90,0}, {255,250,240}};
    //std::array<array<int, 3>, 16> other = {{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{}};
    if(escape == bailout) vertex.color = Color(0,0,0);
    else vertex.color = Color(rgb[escape%16][0], rgb[escape%16][1], rgb[escape%16][2]);
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
            //translate screenpixel to world position
            pair<double,double> RealImgPair = screenToWorld(real, img);
            //calculate escape iterations
            int escape = mandelbrotEscape(RealImgPair);
            //colors
            colorMixer(escape, vertex);
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