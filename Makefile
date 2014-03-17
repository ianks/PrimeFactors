CC = g++-4.9
CXXFLAGS = -std=c++11 -fext-numeric-literals -Wall -O3
EXPENDABLES = PrimeFactors.o TestMain.o TestMain
LIBS =

all:
	@make $(EXPENDABLES)


TestMain: TestMain.o PrimeFactors.o
	$(CC) $(CXXFLAGS) PrimeFactors.o TestMain.o -lm -o TestMain $(LIBS)

PrimeFactors.o: PrimeFactors.h PrimeFactors.cpp
	$(CC) $(CXXFLAGS) -c PrimeFactors.cpp -o PrimeFactors.o $(LIBS)

TestMain.o: PrimeFactors.h TestMain.cpp
	$(CC) $(CXXFLAGS) -c TestMain.cpp -o TestMain.o $(LIBS)


clean:
	rm $(EXPENDABLES)
