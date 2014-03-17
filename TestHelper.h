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
#define TESTS 12

/* Test Integers */
uint1024_t a = 2605796209;
uint1024_t b = 62912768353;
uint1024_t c = 3747841897609;
uint1024_t d = 780421461718057;
uint1024_t e = 3067939880886169;
uint1024_t f = 12749250057165277;
uint1024_t g = 212581611619084489;
uint1024_t h = 2898019909403018077;
uint1024_t i = 0x98F0CB99D6F5332D_cppui1024;                     //20
uint1024_t j = 0xB756E20EE44F043C9BD_cppui1024;                  //23
uint1024_t k = 0xA2A22393F60EB114438792D_cppui1024;              //28
uint1024_t l = 0xC21BD30B38F1B636F2240E44E114D9_cppui1024;       //37

/* Test Objects */
PrimeFactors test01(a);
PrimeFactors test02(b);
PrimeFactors test03(c);
PrimeFactors test04(d);
PrimeFactors test05(e);
PrimeFactors test06(f);
PrimeFactors test07(g);
PrimeFactors test08(h);
PrimeFactors test09(i);
PrimeFactors test10(j);
PrimeFactors test11(k);
PrimeFactors test12(l);


/* Array of Testing Objects */
PrimeFactors obj_array[TESTS] = { test01, test02, test03,
                                  test04, test05, test06,
                                  test07, test08, test09,
                                  test10, test11, test12 };

void constructor_test()
{
  cout << CYAN << "\n-------CONSTRUCTOR-------\n" << endl;

  uint1024_t test_array[TESTS] = { a, b, c, d,
                                   e, f, g, h,
                                   i, j, k, l };

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
  uint1024_t p[TESTS] = {
    51047, 60779, 60647,13500419, 55388987, 13500419, 926867, 14041283, 3296667839
  };

  uint1024_t q[TESTS] = {
    51047, 1035107, 61797647, 57807203, 55388987, 944359583, 229355033267, 206392813919, 3342930707
  };

  for ( unsigned char i = 0; i < TESTS; i++ ){

    obj_array[i].brute_force();
    // check if p and q are correct
    // exclusive-or to make sure each var is only checked once
    bool p_correct = (obj_array[i].p == p[i]);
    bool q_correct = (obj_array[i].q == q[i]);

    if ( p_correct && q_correct )
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

    else
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    cout << "p: " << obj_array[i].p <<endl;
    cout << "q: " << obj_array[i].q <<endl;
  }
}

void sketch_pad()
{
  cout << CYAN << "\n-------SKETCH PAD-------\n" << endl;
  return;
}
