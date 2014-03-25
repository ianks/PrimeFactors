#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include "PrimeFactors.h"
#include "rtdsc.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <future>
#include <iostream>
#include <math.h>
#include <mutex>
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

  void PrimeFactors::find_one_factor(uint1024_t &start) {

    uint1024_t local = n;

    for (uint1024_t i = start; i < sqrt_n; i = i + 10){
      // if p has a value, threads exit function


      if ( p != NULL )
        return;

      if ( local % i == 0 ){
        p = i;
        return;
      }
      if ( local % (i+2) == 0 ){
        p = i+2;
        return;
      }
      if ( local % (i+4) == 0 ){
        p = i+4;
        return;
      }
      if ( local % (i+6) == 0 ){
        p = i+6;
        return;
      }
      if (local % (i+8) == 0 ){
        p = i+8;
        return;
      }
    }
    return;
  }

  void PrimeFactors::brute_force(){

    // need to DRY out this function

    uint1024_t start_arr[4];
    start_arr[0] = 3;
    start_arr[1] = (sqrt_n / 4) | 0x1;
    start_arr[2] = (sqrt_n / 2) | 0x1;
    start_arr[3] = (start_arr[1] + start_arr[2]) | 0x1;

    //for (int i = 0; i < 4; i++){
    //  thread_arr[i] = bind(&PrimeFactors::find_one_factor, this, ref(start_arr[i]));
    //  thread
    //  thread_arr[i].join();
    //}

    auto func1 = bind(&PrimeFactors::find_one_factor, this, ref(start_arr[0]));
    auto func2 = bind(&PrimeFactors::find_one_factor, this, ref(start_arr[1]));
    auto func3 = bind(&PrimeFactors::find_one_factor, this, ref(start_arr[2]));
    auto func4 = bind(&PrimeFactors::find_one_factor, this, ref(start_arr[3]));

    thread th1(func1), th2(func2), th3(func3), th4(func4);
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    q = (n / p);

    return;
  }
}
#endif
