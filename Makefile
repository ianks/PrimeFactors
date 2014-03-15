CC = g++-4.9
FLAGS = -std=c++11 -Wall -g -O3

EXPENDABLES = PrimeFactors.o TestMain.o TestMain

all:
	@make $(EXPENDABLES)


TestMain: TestMain.o PrimeFactors.o
	$(CC) $(FLAGS) PrimeFactors.o TestMain.o -lm -o TestMain

PrimeFactors.o: PrimeFactors.h PrimeFactors.cpp
	$(CC) $(FLAGS) -c PrimeFactors.cpp -o PrimeFactors.o

TestMain.o: PrimeFactors.h TestMain.cpp
	$(CC) $(FLAGS) -c TestMain.cpp -o TestMain.o


clean:
	rm $(EXPENDABLES)
