#ifndef BRUTE_PRIMEFACTORS_H
#define BRUTE_PRIMEFACTORS_H

#include <boost/multiprecision/cpp_int.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace boost::multiprecision;
using namespace boost::multiprecision::literals;
using namespace std;


namespace brute {
  class PrimeFactors
  {
    public:
      /* Constructors, Destructors  */
      PrimeFactors( uint1024_t num );
      ~PrimeFactors();

      /* Variables  */
      uint1024_t n;
      uint1024_t p;
      uint1024_t q;
      uint1024_t sqrt_n;

      /* Functions */
      uint1024_t* get_factors() const
      {
        uint1024_t factors[3] = { get_n(), get_p(), get_q() };
        return factors;
      }

      /* Getters */
      uint1024_t get_n()      const { return n;       }
      uint1024_t get_p()      const { return p;       }
      uint1024_t get_q()      const { return q;       }
      uint1024_t get_sqrt_n() const { return sqrt_n ; }

      bool brute_force();


      /* Operators */
      friend ostream& operator<<(ostream&, const PrimeFactors& prime_factors);

    private:


      /* Setters */
      void set_p( uint1024_t number);
      void set_q( uint1024_t number);

      /* Functions  */
      uint1024_t find_one_factor( uint1024_t &num) const;

  };
}
#endif
