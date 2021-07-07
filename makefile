all:
	g++ -c src/main.cpp src/Application.cpp src/Fractal.cpp 
	g++ main.o Fractal.o Application.o -o Mandelbrot -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
clean:
	rm main.o
	rm Application.o
	rm Fractal.o