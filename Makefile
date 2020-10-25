
FLAGS= -lncurses -pthread -std=c++17
all: main.out

main.out: source/main.cpp backend.o
	g++ source/main.cpp backend.o $(FLAGS) -o main.out

backend.o: source/backend.cpp
	g++ -c source/backend.cpp $(FLAGS) -o backend.o

clean:
	rm main.out
	rm backend.o