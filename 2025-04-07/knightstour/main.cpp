#include <iostream>
#include <vector>

bool knightstour(int n, std::vector< std::pair< int, int > > & solution)
{
    return true;
}

std::ostream & operator<<(std::ostream & cout,
                          const std::vector< std::vector< int > > & board)
{
    for (auto && row: board)
    {
        for (auto && e: row)
        {
            std::cout << e << '|';
        }
        std::cout << '\n';
    }
}
                          
int main()
{
    int n;
    std::cin >> n;
    std::vector< std::pair< int, int > > solution;
    std::vector< std::vector< int > > board(n, std::vector< int >(n, -1));

    bool b = knightstour(n, solution);
    if (b)
    {
        std::cout << "success ... solution is\n";
    }
    else
    {
        std::cout << "failure\n";
    }
    return 0;
}
