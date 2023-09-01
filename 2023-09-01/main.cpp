#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f0(1, 2);
    //std::cout << f0.n() << '/' << f0.d() << '\n'; // tedious

    std::cout << f0 << '\n'; // better

    f0.set_n(42); 
    std::cout << f0 << '\n'; // better

    // (std::cout << f0) is the same
    // operator<<(std::cout, f0)

    // f0 + f1

    Fraction f1(1, 0);
    std::cout << f1 << '\n'; // better

    Fraction f2(3, 1);
    std::cout << f2 << '\n'; // better

    return 0;
}
