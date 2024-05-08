all: snatan
snatan:
	g++ -std=c++17 -W -O3 -march=native -o snatan *.cpp -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
.PHONY:
	clean all
clean:
	rm snatan
