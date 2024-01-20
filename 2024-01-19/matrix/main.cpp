#include <iostream>
#include "Matrix.h"

void f()
{
    Matrix m(2, 3);
    std::cout << m << '\n';
    
    m(0, 0) = 5; // m.operator()(0, 0) = 5
    std::cout << m << '\n';

    // test destructor
    for (int i = 0; i < 5; ++i)
    {
        Matrix n(100, 200);
    }
    
    // test copy constructor
    Matrix n(m);
    std::cout << n << '\n';
    
    // test operator=
    Matrix p(10, 10);
    p = m;
    std::cout << p << '\n';
}

int main()
{
    f();
    return 0;
}
