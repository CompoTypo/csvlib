build:
	g++ main.cpp Table.hpp MathStats.hpp -o main -g

run:
	./main boston.csv

debug:
	gdb ./main