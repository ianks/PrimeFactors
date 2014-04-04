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
    PrimeFactors( int1024_t num );

    /* Variables  */
    int1024_t n;
    int1024_t p;
    int1024_t q;
    int1024_t sqrt_n;

    /* Functions */
    void brute_force();
    inline void find_one_factor( int1024_t &start );
    void pollard_strassen();

    /* Getters */
    int1024_t  get_n()       const { return n;       }
    int1024_t  get_p()       const { return p;       }
    int1024_t  get_q()       const { return q;       }
    int1024_t  get_sqrt_n()  const { return sqrt_n ; }
    int1024_t* get_factors() const
    {
      int1024_t factors[3] = { get_n(), get_p(), get_q() };
      return factors;
    }
  };
}
#endif
