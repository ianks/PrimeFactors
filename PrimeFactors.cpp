#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include "PrimeFactors.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <math.h>
#include <thread>
#include <future>

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

  uint1024_t PrimeFactors::find_one_factor(uint1024_t &start) const{

    for (uint1024_t i = start; i < n; i = i+2){
      if (n % i == 0 && i != 1)
          return i;
      }
    return 0;
  }

  void PrimeFactors::brute_force(){
    uint1024_t start;

    unsigned char num_threads = thread::hardware_concurrency();
    future<uint1024_t> future_array[num_threads];

    for (unsigned char i = 0; i < num_threads; i++){
      start = 1;
      // bind captures the instances find_one_factor() pointer
      // must pass uint1024_t by reference
      auto func = bind(&PrimeFactors::find_one_factor, this, ref(start));
      future_array[i] = async(func);
    }

    try{
      p = future_array[0].get();
      q = n / p;
    }

    catch(exception & e){
      cout << e.what() << endl;
    }

    return;
  }
}
#endif
