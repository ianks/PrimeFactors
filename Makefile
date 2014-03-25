CC = g++-4.8
CXXFLAGS = -std=c++11 -fext-numeric-literals -Wall -Ofast
EXPENDABLES = PrimeFactors.o TestMain.o TestMain

all:
	@make $(EXPENDABLES)


TestMain: TestMain.o PrimeFactors.o
	$(CC) $(CXXFLAGS) PrimeFactors.o TestMain.o -lm -o TestMain

PrimeFactors.o: PrimeFactors.h PrimeFactors.cpp
	$(CC) $(CXXFLAGS) -c PrimeFactors.cpp -o PrimeFactors.o

TestMain.o: PrimeFactors.h TestMain.cpp
	$(CC) $(CXXFLAGS) -c TestMain.cpp -o TestMain.o

test: TestMain
	./TestMain

clean:
	rm $(EXPENDABLES)
