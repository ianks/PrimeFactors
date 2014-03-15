#include <boost/lexical_cast.hpp>
#include <iostream>
#include <thread>
#include <string>

#include "uint256.h"
#include "PrimeFactors.h"

using namespace std;
using namespace boost;
using namespace brute;

//Global ANSI Colors
#define PASS    "\033[0;32m"
#define FAIL    "\033[0;31m"
#define CYAN    "\033[0;36m"

#define TESTS 5

PrimeFactors test1(21);
PrimeFactors test2(2451);
PrimeFactors test3(9191);
PrimeFactors test4(5509);
PrimeFactors test5(7275125959881829066786422208675011267193);

PrimeFactors obj_array[TESTS] = { test1, test2, test3, test4, test5 };

void constructor_test()
{
  cout << CYAN << "\n-------CONSTRUCTOR-------\n" << endl;

  uint256 test_array[TESTS] = { 21, 2451, 9191, 5509, 7275125959881829066786422208675011267193 };

  for ( unsigned char i = 0; i < TESTS; i++ ){

    bool correct = ( obj_array[i].get_n() == test_array[i] );

    if ( !correct )
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    else
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

  }

  cout << endl;
  return;
}

void brute_force_test()
{
  cout << CYAN << "\n------- BRUTE FORCE-------\n" << endl;

  uint256 p[TESTS] = { 3, 43,  91, 131, 76109378112451927699 };
  uint256 q[TESTS] = { 7, 57, 101,  37, 95587773022304816707 };

  for ( unsigned char i = 0; i < TESTS; i++ ){

    bool correct = ( ( obj_array[i].get_p() == p[i] ) != ( obj_array[i].get_q() == q[i] ) );

    if ( !correct )
      cout << FAIL << "[  ] Test" << lexical_cast<string>(i+1) << " failed." << endl;

    else
      cout << PASS << "[xx] Test" << lexical_cast<string>(i+1) << " passed." << endl;

  }
}

void sketch_pad()
{
  cout << CYAN << "\n-------SKETCH PAD-------\n" << endl;
  return;
}
