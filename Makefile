String: main.o
	g++ -std=c++11 -g -o String main.o
main.o: main.cc
	g++ -std=c++11 -g -c -o main.o main.cc

