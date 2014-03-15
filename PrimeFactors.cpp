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
    PrimeFactors::brute_force( uint256 &n ){
        return true;
    }
}

#endif
