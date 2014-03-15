#ifndef BRUTE_PRIMEFACTORS_H
#define BRUTE_PRIMEFACTORS_H

#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

namespace brute {
    class PrimeFactors
    {
        public:
            /* Constructors, Destructors  */
            PrimeFactors( unsigned int num );
            ~PrimeFactors();

            /* Functions */
            unsigned int*get_factors() const
            {
                unsigned int factors[3] = { get_n(), get_p(), get_q() };
                return factors;
            }

            inline unsigned int  get_n() const { return n; }
            inline unsigned int  get_p() const { return q; }
            inline unsigned int  get_q() const { return q; }


            /* Operators */
            friend ostream& operator<<(ostream&, const PrimeFactors& prime_factors);

        private:
            /* Variables  */
            unsigned long long int n;
            unsigned long long int p;
            unsigned long long int q;

            /* Functions */
            inline unsigned int* brute_force( unsigned int &num );
    };
}
#endif
