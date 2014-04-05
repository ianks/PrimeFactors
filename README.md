RSA-Crack
==========

This is a C++ class to crack small RSA-style private keys by finding prime factors (p,q) for n = p * q

1. Create a new PrimeFactors instance
    ```
    PrimeFactors myPrimeFactors(myHexValue);
    ```

2. List the Primefactors (Warning: this could be ahile. Get a coffee... or two... or ~infinity depending on your number!)
    ```
    myPrimeFactors.get_n();
    myPrimeFactors.get_p();
    myPrimeFactors.get_q();
    ```

#### Notes

1. Requires c++11 std-lib and gcc-4.8 or newer
2. For large hex values, use the Ruby Script (hex_converter.rb) to generate the literal hex value


#### Running the Program
1. ```make```
2. ```./TestMain --phollard``` ```./TestMain --brute-force```


####Assignment Write-Up

My goal in the assignment was the speed of C++ to perform prime factorization. I wanted to make this class easily usable by other others, so I decided to make it a class that could be included in other projects. I also decided to write a test suite to verify my code easily. One of my goals was to implement multi-threading into my program. After hours of trying to figure out the correct way to do it, I settled on attempting to use C++11's new threading features. This turned out to be a bit harder than expected. After finally getting it working, it actually slowed down my program by a decent bit! I knew this because I implemented CPU Cycle counting in my program. I later tried using OpenMP, however the inablity to break out of a loop in Open MP was not optimal for this style of 'Search'. Overall I learned how difficulty to crack numbers increases exponentially as one would mathematically expect. Overall, the test can crack 33-digit numbers in about 1-2 minutes. After that is starts taking exponentially longer.
