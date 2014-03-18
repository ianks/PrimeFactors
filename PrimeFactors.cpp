#ifndef BRUTE_PRIMEFACTORS_CPP
#define BRUTE_PRIMEFACTORS_CPP

#include "PrimeFactors.h"

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
    // cout<< "Thread ID: " << this_thread::get_id() << endl;
    // cout<< "Start Value: " << this_thread::get_id() << endl;

    for (uint1024_t i = start; i < n; i = i + 2){
      // if p has a value, threads exit function
      if (p != NULL)
        return;

      if ( n % i == 0 ){
        p = i;
        return;
      }
    }
  }

  void PrimeFactors::brute_force(){

    // need to DRY out this function

    uint1024_t start1 = 3;
    uint1024_t start2 = (sqrt_n / 4) | 0x1;
    uint1024_t start3 = (sqrt_n / 2) | 0x1;
    uint1024_t start4 = (start2 + start3) | 0x1;

    auto func1 = bind(&PrimeFactors::find_one_factor, this, ref(start1));
    auto func2 = bind(&PrimeFactors::find_one_factor, this, ref(start2));
    auto func3 = bind(&PrimeFactors::find_one_factor, this, ref(start3));
    auto func4 = bind(&PrimeFactors::find_one_factor, this, ref(start4));

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
