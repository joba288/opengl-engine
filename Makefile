CFLAGS=-O2 -Wall -std=c++11
SRC = $(wildcard src/*.cpp)
build:
	g++ -v $(SRC) src/glad.c -o main.exe $(CFLAGS) 	\
	-I ./include/ -L ./lib/ 		    \
	-lglfw3dll -lopengl32 -lglu32 -lgdi32 -lwinmm
run: build
	./main.exe