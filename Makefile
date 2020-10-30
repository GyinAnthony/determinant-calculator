one: main.o Matrix.o Executive.o
	g++ -g -Wall -std=c++11 main.o Matrix.o Executive.o -o one
main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp
Matrix.o: Matrix.h Matrix.cpp
	g++ -g -Wall -std=c++11 -c Matrix.cpp
Executive.o: Executive.h Executive.cpp Matrix.h
	g++ -g -Wall -std=c++11 -c Executive.cpp

clean:
	rm *.o one
