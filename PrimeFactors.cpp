#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include "PrimeFactors.h"
#include "rtdsc.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <future>
#include <iostream>
#include <math.h>

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

  inline void PrimeFactors::find_one_factor(uint1024_t &start) {

    long long cycStart, cycStop;
    cycStart = rdtscll();
    uint1024_t local = n;

    for (uint1024_t i = start; i < sqrt_n; i = i + 10){
      // if p has a value, threads exit function


      if ( p != NULL )
        return;

      if ( local % i == 0 ){
        p = i;
        goto finish;
      }
      if ( local % (i+2) == 0 ){
        p = i+2;
        goto finish;
      }
      if ( local % (i+4) == 0 ){
        p = i+4;
        goto finish;
      }
      if ( local % (i+6) == 0 ){
        p = i+6;
        goto finish;
      }
      if (local % (i+8) == 0 ){
        p = i+8;
        goto finish;
      }
    }
    finish:
      cycStop = rdtscll();
      float diff = cycStop - cycStart;
      cout << "Cycles to Process: " << diff << endl;
      return;
  }

  void PrimeFactors::brute_force(){

    // need to DRY out this function

    uint1024_t start_arr[4];
    start_arr[0] = 3;
    start_arr[1] = (sqrt_n / 4) | 0x1;
    start_arr[2] = (sqrt_n / 2) | 0x1;
    start_arr[3] = (start_arr[1] + start_arr[2]) | 0x1;

    find_one_factor(start_arr[0]);

    q = (n / p);

    return;
  }

  void PrimeFactors::pollard_strassen(){

    if (n%2 == 0)
      return;

    long long cycStart, cycStop;
    cycStart = rdtscll();

    uint1024_t a = rand() % n + 1;
    uint1024_t b = a;
    uint1024_t c = rand() % n + 1;
    p = 1;


    while ( p == 1 ){
      a = ((a*a) % n + c) % n;
      b = ((b*b) % n + c) % n;
      b = ((b*b) % n + c) % n;
      uint1024_t abso = a-b;

      p = gcd(abso, n);
    }

    q = (n / p);

    cycStop = rdtscll();
    float diff = cycStop - cycStart;
    cout << "Cycles to Process: " << diff << endl;
    return;
  }
}
#endif
