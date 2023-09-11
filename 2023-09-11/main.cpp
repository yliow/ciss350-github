#include <iostream>
#include <vector>
#include "Matrix.h"

int main()
{
    // vector demo
    // int x[10];
    // std::vector< int > y(10);
    // std::cout << y.size() << '\n';
    // y[0] = 42;
    // std::cout << y[0] << '\n';
    // for (int i = 0; i < y.size(); ++i)
    // {
    //     std::cout << y[i] << ' ' ;
    // }
    // std::cout << '\n';

    // y.push_back(9000);
    // std::cout << y.size() << '\n';
    // for (int i = 0; i < y.size(); ++i)
    // {
    //     std::cout << y[i] << ' ' ;
    // }
    // std::cout << '\n';

    // y.push_back(9001);
    // std::cout << y.size() << '\n';
    // for (int i = 0; i < y.size(); ++i)
    // {
    //     std::cout << y[i] << ' ' ;
    // }
    // std::cout << '\n';

    // for (int i = 0; i < 10; ++i)
    // {
    //     y.push_back(i);
    // }
    // std::cout << y.size() << '\n';
    // for (int i = 0; i < y.size(); ++i)
    // {
    //     std::cout << y[i] << ' ' ;
    // }
    // std::cout << '\n';

    Matrix m(2, 3);
    std::cout << m.nrows() << ' ' << m.ncols() <<  '\n';
    std::cout << m << '\n';

    std::cout << m(1, 2) << '\n'; // m(1, 2) = m.operator()(1, 2)
    m(1, 2) = 42;
    std::cout << m << '\n';

    Matrix m1(m);

    return 0;
} // m calls m.~Matrix()
