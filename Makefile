Tickets: main.o
	g++ -std=c++11 -g -o Tickets main.o
main.o: main.cc
	g++ -std=c++11 -g -c -o main.o main.cc

