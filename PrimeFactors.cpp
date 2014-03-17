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

  uint1024_t PrimeFactors::find_one_factor( uint1024_t key) const{
    for (uint1024_t i = 2; i < sqrt_n; i++){
      cout << sqrt_n << endl;
      if (key % i == 0)
        if (i != p && i != q)
          return i;
    }
  }

  bool PrimeFactors::brute_force(){

    uint1024_t key = n;

    p = find_one_factor(key);
    q = find_one_factor(key);

    return true;
  }
}

#endif
