#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include <math.h>
#include <iostream>
#include <thread>

#include "uint256.h"
#include "PrimeFactors.h"

using namespace std;

namespace brute {

    PrimeFactors::PrimeFactors( unsigned int num ){
        n = num;
    }

    PrimeFactors::~PrimeFactors(){

    }

    inline unsigned int*
    brute_force( unsigned int &num ){

        unsigned int factors[2];
        return factors;
    }
}

#endif
