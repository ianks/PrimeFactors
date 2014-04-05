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
#define TESTS   15

/* Test Integers */
int512_t a = 2605796209;
int512_t b = 62912768353;
int512_t c = 3747841897609;
int512_t d = 780421461718057;
int512_t e = 3067939880886169;
int512_t f = 12749250057165277;
int512_t g = 212581611619084489;
int512_t h = 2898019909403018077;
int512_t i = 0x98F0CB99D6F5332D_cppui512;                     //20
int512_t j = 0xB756E20EE44F043C9BD_cppui512;                  //23
int512_t k = 0xA2A22393F60EB114438792D_cppui512;              //28
int512_t l = 0x3010B252BC7C50407E2BAD8E9_cppui512;            //30
int512_t m = 0xCAA9D2523028D2397E8FC8AE5_cppui512;            //31
int512_t n = 0x263173580F112EBD35F9D8B73369_cppui512;         //33
int512_t o = 0xC21BD30B38F1B636F2240E44E114D9_cppui512;       //37

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
PrimeFactors test13(m);
PrimeFactors test14(n);
PrimeFactors test15(o);


/* Array of Testing Objects */
PrimeFactors obj_array[TESTS] = { test01, test02, test03,
                                  test04, test05, test06,
                                  test07, test08, test09,
                                  test10, test11, test12,
                                  test13, test14, test15 };

void constructor_test()
{
  cout << CYAN << "\n-------CONSTRUCTOR-------\n" << PASS << endl;

  int512_t test_array[TESTS] = {   a, b, c, d,
                                   e, f, g, h,
                                   i, j, k, l,
                                   m, n, o };

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
  cout << CYAN << "\n------- BRUTE FORCE-------\n" << PASS << endl;

  for ( unsigned char i = 0; i < TESTS; i++ ){

    obj_array[i].brute_force();
    // check if p and q are correct
    // exclusive-or to make sure each var is only checked once
    bool correct = (obj_array[i].p  * obj_array[i].q == obj_array[i].n );

    if ( correct )
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

    else
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    cout << "p: " << obj_array[i].p <<endl;
    cout << "q: " << obj_array[i].q <<endl;
  }
}

void pho_test()
{
  cout << CYAN << "\n------- POLLARD ALGORITHM-------\n" << PASS << endl;

  for ( unsigned char i = 0; i < TESTS; i++ ){

    obj_array[i].pollard_strassen();
    // check if p and q are correct
    // exclusive-or to make sure each var is only checked once
    bool correct = (obj_array[i].p  * obj_array[i].q == obj_array[i].n );

    if ( correct )
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
