#include <iostream>

void println(int [], int, int);
void print(int [], int, int);
void primes(int [], int end); // fill x with `end` number of primes 


int main()
{
    int x[] = {2, 3, 5, 7, 11, 13, 17, 19};
    print(x, 0, 5);

    return 0;    
}


void print(int x[], int start, int end)
{
    std::cout << '{';
    for (int i = start; i < end; ++i)
    {
        std::cout << x[i];
        if (i < end - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << '}';
    return;
}


void print(int * start, int * end)
{
    std::cout << '{';
    for (int * p = start; p < end; ++p)
    {
        std::cout << (*p);
        if (p < end - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << '}';
    return;
}




void println(int x[], int start, int end)
{
    print(x, start, end);
    std::cout << '\n';
    return;
}

