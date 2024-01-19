#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix m(2, 3);
    std::cout << m << '\n';
    int x[10];

    m(0, 0) = 5; // m.operator()(0, 0) = 5
    
    return 0;
}
