#include <iostream>

void println(int x[], int n);
void print(int x[], int n);


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


void println(int x[], int start, int end)
{
    print(x, start, end);
    std::cout << '\n';
    return;
}

