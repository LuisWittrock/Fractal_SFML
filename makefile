
all:
	g++ -c src/main.cpp
	g++ main.o -o Mandelbrot -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	rm main.o