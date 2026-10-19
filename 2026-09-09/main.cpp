#include <iostream>
#include "Mat.h"

int main()
{
    Mat M(2, 3);
    std::cout << M << '\n';
    M(0,0) = 1;
    M(0,1) = 2;
    M(0,2) = 3;
    M(1,0) = 0;
    M(1,1) = 5;
    M(1,2) = 4;
    std::cout << M << '\n';

    //Mat P(M);
    //P = M;
    //P = P;
    
    Mat N(2, 3);
    N(0,0) = -1;
    N(0,1) = -2;
    N(0,2) = 4;
    N(1,0) = 3;
    N(1,1) = -1;
    N(1,2) = -2;
    std::cout << N << '\n';

    M += N;
    std::cout << M << '\n';

    M = M + N;
    std::cout << M << '\n';

    N = M * 3;
    std::cout << N << '\n';
    
    return 0;
}
