#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include <math.h>
#include <iostream>
#include <thread>

#include "uint256.h"
#include "PrimeFactors.h"

using namespace std;

namespace brute {

    PrimeFactors::PrimeFactors( uint256 num ){
        n = num;
    }

    PrimeFactors::~PrimeFactors(){

    }

    bool
    brute_force( unsigned int &num ){

        return true;
    }
}

#endif
