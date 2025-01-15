#include <iostream>
#include "Mat.h"

int main()
{
    Mat m(2, 3);
    Mat n(m); // or Mat n = m;

    n = m; // n.operator=(m)
}

