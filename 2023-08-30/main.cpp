#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f0;
    std::cout << f0.n() << '/' << f0.d() << '\n'; // tedious

    std::cout << f0 << '\n'; // better

    // (std::cout << f0) is the same
    // operator<<(std::cout, f0)

    // f0 + f1
    
    return 0;
}
