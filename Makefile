CC = g++
FLAGS = -Wall -g
LIBS =

EXPENDABLES = PrimeFactors TestMain.o TestMain

all: PrimeFactors.o TestMain.o TestMain


TestMain: PrimeFactors TestMain.o
	$(CC) $(FLAGS) PrimeFactors TestMain.o -lm -o TestMain

PrimeFactors: PrimeFactors.h PrimeFactors.cpp
	$(CC) $(FLAGS) -c PrimeFactors.cpp -o PrimeFactors $(LIBS)

TestMain.o: PrimeFactors.h TestMain.cpp
	$(CC) $(FLAGS) -c TestMain.cpp -o TestMain.o $(LIBS)


clean:
	rm $(EXPENDABLES)
