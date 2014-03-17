#include "PrimeFactors.h"

#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <thread>
#include <string>

using namespace std;
using namespace boost;
using namespace boost::multiprecision;
using namespace boost::multiprecision::literals;
using namespace brute;

/* Global Variables */
#define PASS    "\033[0;32m"
#define FAIL    "\033[0;31m"
#define CYAN    "\033[0;36m"
#define TESTS 5

/* Test Integers */
uint1024_t a = 21;
uint1024_t b = 2451;
uint1024_t c = 9191;
uint1024_t d = 5509;
uint1024_t e = 0x1561324b24f2bccf2365749c5d6a6a8a79_cppui1024;

/* Test Objects */
PrimeFactors test1(a);
PrimeFactors test2(b);
PrimeFactors test3(c);
PrimeFactors test4(d);
PrimeFactors test5(e);


/* Array of Testing Objects */
PrimeFactors obj_array[TESTS] = { test1, test2, test3, test4, test5 };

void constructor_test()
{
  cout << CYAN << "\n-------CONSTRUCTOR-------\n" << endl;

  uint1024_t test_array[TESTS] = { a, b, c, d, e };

  for ( unsigned char i = 0; i < TESTS; i++ ){

    bool correct = ( obj_array[i].n == test_array[i] );

    if ( correct )
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

    else
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    cout << "n = " << obj_array[i].n << endl;
  }

  cout << endl;
  return;
}

void brute_force_test()
{
  cout << CYAN << "\n------- BRUTE FORCE-------\n" << endl;

  /* Correct p and q  Factors */
  uint1024_t p[TESTS] = { 3, 43,  91, 131, 0x4203ad42604965e93_cppui1024 };
  uint1024_t q[TESTS] = { 7, 57, 101,  37, 0x52e8bfd1e39254e43_cppui1024 };

  for ( unsigned char i = 0; i < TESTS; i++ ){

    obj_array[i].brute_force();
    // check if p and q are correct
    // exclusive-or to make sure each var is only checked once
    bool p_correct = ( (obj_array[i].p == p[i]) != (obj_array[i].p == q[i]) );
    bool q_correct = ( (obj_array[i].q == p[i]) != (obj_array[i].q == q[i]) );

    if ( p_correct && q_correct )
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

    else
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;
  }
}

void sketch_pad()
{
  cout << CYAN << "\n-------SKETCH PAD-------\n" << endl;
  test5.brute_force();
  return;
}
