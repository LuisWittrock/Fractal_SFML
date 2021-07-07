#include "Application.hpp"

Application::Application() :
    fractal(WINDOW_HEIGHT, WINDOW_WIDTH, bailout)
{
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mandelbrot");
}
void Application::start()
{
    while(window.isOpen())
    {
        while(window.pollEvent(event)) if(event.type == Event::Closed) window.close();
        
        draw();
    }
    
}
void Application::draw()
{
    window.clear();
    
    window.draw(fractal.calcMandelbrot());

    window.display();
}
void Application::update()
{
    
}