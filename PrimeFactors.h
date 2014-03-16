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

            /* Functions */
            uint1024_t* get_factors() const
            {
                uint1024_t factors[3] = { get_n(), get_p(), get_q() };
                return factors;
            }

            inline uint1024_t get_n() const { return n; }
            inline uint1024_t get_p() const { return q; }
            inline uint1024_t get_q() const { return q; }

            /* Operators */
            friend ostream& operator<<(ostream&, const PrimeFactors& prime_factors);

        private:
            /* Variables  */
            uint1024_t n;
            uint1024_t p;
            uint1024_t q;

            /* Functions */
            bool brute_force( checked_uint1024_t &num );
    };
}
#endif
