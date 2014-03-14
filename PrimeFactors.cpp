#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include <boost/thread.hpp>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include "PrimeFactors.h"

using namespace boost;
using namespace boost::this_thread;
using namespace std;

namespace brute {

    PrimeFactors::PrimeFactors(unsigned int num){
        n = num;
        this->get_factors();
    }

    PrimeFactors::~PrimeFactors(){

    }

    inline unsigned int*
    brute_force(unsigned int &num){

        unsigned int factors[2];

        return factors;
    }
}

#endif
