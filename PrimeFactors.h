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
    PrimeFactors( int512_t num );

    /* Variables  */
    int512_t n;
    int512_t p;
    int512_t q;
    int512_t sqrt_n;

    /* Functions */
    void brute_force();
    inline void find_one_factor( int512_t &start );
    void pollard_strassen();

    /* Getters */
    int512_t  get_n()       const { return n;       }
    int512_t  get_p()       const { return p;       }
    int512_t  get_q()       const { return q;       }
    int512_t  get_sqrt_n()  const { return sqrt_n ; }
    int512_t* get_factors() const
    {
      int512_t factors[3] = { get_n(), get_p(), get_q() };
      return factors;
    }
  };
}
#endif
