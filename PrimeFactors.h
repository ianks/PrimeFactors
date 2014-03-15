#ifndef BRUTE_PRIMEFACTORS_H
#define BRUTE_PRIMEFACTORS_H

#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string>

#include "uint256.h"

using namespace std;

namespace brute {
    class PrimeFactors
    {
        public:
            /* Constructors, Destructors  */
            PrimeFactors( uint256 num );
            ~PrimeFactors();

            /* Functions */
            uint256* get_factors()
            {
                this->brute_force(n);
                uint256 factors[3] = { get_n(), get_p(), get_q() };
                return factors;
            }

            inline uint256 get_n() const { return n; }
            inline uint256 get_p() const { return q; }
            inline uint256 get_q() const { return q; }


            /* Operators */
            friend ostream& operator<<(ostream&, const PrimeFactors& prime_factors);

        private:
            /* Variables  */
            uint256 n;
            uint256 p;
            uint256 q;

            /* Functions */
            bool brute_force( uint256 &num );
            inline void set_p(uint256 factor) { p = factor; return; }
            inline void set_q(uint256 factor) { q = factor; return; }
    };
}
#endif
