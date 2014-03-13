#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include "PrimeFactors.h"

using namespace std;
using namespace boost;
using namespace brute;

//Global ANSI Colors
#define PASS     "\033[0;32m"
#define FAIL      "\033[0;31m"
#define CYAN    "\033[0;36m"

#define TESTS 9

PrimeFactors test1(21);
PrimeFactors test2(479);
PrimeFactors test3(881);
PrimeFactors test4(1609);
PrimeFactors test5(2251);
PrimeFactors test6(3023);
PrimeFactors test7(4967);
PrimeFactors test8(5227);
PrimeFactors test9(10069);

PrimeFactors obj_array[9] = { test1, test2, test3,
                                               test4, test5, test6,
                                               test7, test8, test9 };

void constructor_test()
{
  cout << CYAN << "\n-------CONSTRUCTOR-------\n" << endl;

  unsigned int test_array[9] = {
    21, 479, 881, 1609, 2251, 3023, 4967, 5227, 10069
  };

  for (int i = 0; i < TESTS; i++){

    bool finished = ( obj_array[i].get_n() == test_array[i] );

    if (!finished)
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    else
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;
  }

  cout << endl;
}
