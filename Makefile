all: program1

program1: Main.o LCS_bottom-up.o
	g++ -std=c++11 -o program1 Main.o LCS_bottom-up.o
	
Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

LCS_bottom-up.o: LCS_bottom-up.cpp
	g++ -std=c++11 -c LCS_bottom-up.cpp

clean:
	rm -vf *.o program*