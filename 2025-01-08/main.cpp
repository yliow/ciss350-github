#include <iostream>
#include <cstdlib>
#include <ctime>

void f3()
{
    int count = 0;
    while (1)
    {
        char coin = (rand() % 2 == 0 ? 'H' : 'T');
        std::cout << coin << ' ';
        // if (coin == 'H')
        // {
        //     ++count;
        // }
        // else
        // {
        //     count = 0;
        // }
        count = (coin == 'H' ? count + 1 : 0);

        if (count == 3) break;
    }
    std::cout << '\n';
}
void f2()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        // print spaces
        for (int j = 0; j < n - i; ++j)
        {
            std::cout << ' ';
        }
        // print stars
        for (int j = 0; j < i; ++j)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void f1()
{
    int n;
    std::cin >> n;
    for (int i = n; i > 0; --i)
    {
        for (int j = i;  j >= 1; --j)
        // or for (int j = 0;  j < i; ++j)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}
void f0()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        // {
        //     std::cout << '*';
        // }
        // else
        // {
        //     std::cout << '@';
        // }
        // OR:
        {
            std::cout << (i % 2 == 0 ? '*' : '@');
        }
    }
    std::cout << '\n';
}

int numdigits(int n)
{
    if (n == 0) return 1;
    else
    {
        int count = 0; // count digits
        while (n != 0)
        {
            n /= 10;
            ++count;
        }
        return count;
    }
}
int numevendigits(int n)
{
    if (n == 0) return 1;
    else
    {
        int count = 0; // count number of even digits
        while (n != 0)
        {
            int digit = n % 10;
            n /= 10;
            if (digit % 2 == 0) ++count;
        }
        return count;
    }
}

void f4()
{
    int n;
    std::cin >> n;
    std::cout << numdigits(n) << '\n';
}

int main()
{
    srand((unsigned int) time(NULL));
    //f0();
    //f1();
    //f2();
    //f3();
    f4();
    return 0;
}
