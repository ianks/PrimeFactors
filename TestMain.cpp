#include "TestHelper.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if (argv[1] == NULL){
    cout << "Please provide input arguments. For more info: ./TestMain --help" << endl;
    return 0;
  }

  string input = argv[1];

  if (input == "--help"){
    cout << "Options: --constructor-test --brute_force --phollard --sketch-pad" << endl;
    return 0;
  }

  if (input == "--constructor"){
    constructor_test();
    return 0;
  }

  if (input == "--brute_force"){
    brute_force_test();
    return 0;
  }

  if (input == "--phollard"){
    pho_test();
    return 0;
  }

  if (input == "--sketch_pad"){
    sketch_pad();
    return 0;
  }

  return 0;
}

