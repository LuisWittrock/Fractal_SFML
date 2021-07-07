#include "Application.hpp"

Application::Application() : fractal(WINDOW_HEIGHT, WINDOW_WIDTH, bailout)
{
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mandelbrot");
}
void Application::start()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();
        update();
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
    draw();
    checkKeys();
}
void Application::checkKeys()
{
    while (1)
    {
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            fractal.normalize();
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            fractal.zoomIn();
            break;
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            fractal.zoomOut();
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            fractal.move(3);
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            fractal.move(4);
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            fractal.move(2);
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            fractal.move(1);
            break;
        }
        if(Keyboard::isKeyPressed(Keyboard::R))
        {
            fractal.changePrecision(16);
            break;
        }
        if(Keyboard::isKeyPressed(Keyboard::F))
        {
            fractal.changePrecision(-16);
            break;
        }
    }
}