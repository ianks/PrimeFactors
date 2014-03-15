### RSA Crack

This is a C++ multithreaded C++ class to crack small RSA-style private keys by finding prime factors (p,q) for n = p * q

1. Create a new PrimeFactors instance
    ```
    PrimeFactors myPrimeFactors(myHexValue);
    ```

2. List the Primefactors (Warning: this could be ahile. Get a coffee... or two... or ~infinity depending on your number!)
    ```
    myPrimeFactors.get_factors();
    ```

#### Notes

1. Requires c++11 std lib
2. Candle handle up to 256bit integer input
