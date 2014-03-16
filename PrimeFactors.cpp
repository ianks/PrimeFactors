#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include "PrimeFactors.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <math.h>
#include <thread>

using namespace boost::multiprecision;
using namespace boost::multiprecision::literals;
using namespace std;

namespace brute {

    PrimeFactors::PrimeFactors( uint1024_t num ){
        n = num;
    }

    PrimeFactors::~PrimeFactors(){

    }

    bool
    brute_force( uint1024_t &num ){

        return true;
    }
}

#endif
