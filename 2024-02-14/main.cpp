#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector< int > x;
    x.resize(10);

    // for (unsigned int i = 0; i < x.size(); ++i)
    // {
    //     x[i] = rand() % 10;
    // }

    for (auto && e: x)
    {
        e = rand() % 10;
    }

    // for (unsigned int i = 0; i < x.size(); ++i)
    // {
    //     std::cout << x[i] << ' ' ;
    // }
    // std::cout << '\n';

    for (auto && e: x)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    std::sort(&x[0], &x[10], [](int a, int b){ return a > b; } );

    for (auto && e: x)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
