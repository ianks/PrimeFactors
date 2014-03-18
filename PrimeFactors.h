#ifndef BRUTE_PRIMEFACTORS_H
#define BRUTE_PRIMEFACTORS_H

#include <boost/multiprecision/cpp_int.hpp>
#include <cstdlib>
#include <mutex>
#include <iostream>
#include <string>
#include <future>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::multiprecision::literals;

namespace brute {
  class PrimeFactors
  {
    public:
    /* Constructors, Destructors  */
    PrimeFactors( uint1024_t num );

    /* Variables  */
    uint1024_t n;
    uint1024_t p;
    uint1024_t q;
    uint1024_t sqrt_n;

    /* Functions */
    void brute_force();
    void find_one_factor( uint1024_t &start );

    /* Getters */
    uint1024_t  get_n()       const { return n;       }
    uint1024_t  get_p()       const { return p;       }
    uint1024_t  get_q()       const { return q;       }
    uint1024_t  get_sqrt_n()  const { return sqrt_n ; }
    uint1024_t* get_factors() const
    {
      uint1024_t factors[3] = { get_n(), get_p(), get_q() };
      return factors;
    }
  };
}
#endif
