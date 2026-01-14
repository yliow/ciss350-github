#include <iostream>
#include <cstdlib>
#include <ctime>

char coin_toss()
{
    return (rand() % 2 == 0 ? 'H' : 'T');
}

int main()
{
    /*
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        //std::cout << n - (i + 1) << ' ' << i + 1 << '\n';
        // print spaces
        for (int j = 0; j < n - (i + 1); ++j)
        {
            std::cout << ' ';
        }
        // draw the triangle part
        for (int j = 0; j < i + 1; ++j)
        {
            std::cout << (j % 2 == 0 ? '*' : '-');
        }
        std::cout << '\n';
    }
    return 0;
    */
    srand((unsigned int) time(NULL));
    int count = 0; // counts heads
    while (count < 3)
    {
        char coin = coin_toss();
        std::cout << coin << ' ';
        if (coin == 'H')
        {
            ++count;
        }
        else
        {
            count = 0;
        }
    }
    std::cout << '\n';
    
    return 0;
}
