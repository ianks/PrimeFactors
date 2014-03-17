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
    p = 0;
    q = 0;
    sqrt_n = sqrt(n);
  }

  PrimeFactors::~PrimeFactors(){

  }

  uint1024_t PrimeFactors::find_one_factor( uint1024_t &key) const{

    for (uint1024_t i = 1; i < n; i = i+2){
      if (key % i == 0 && i != 1)
          return i;
    }
    return 0;
  }

  bool PrimeFactors::brute_force(){
    p = find_one_factor(n);
    q = n / p;
    return true;
  }
}

#endif
