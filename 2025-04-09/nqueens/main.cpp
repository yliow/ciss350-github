#include <iostream>
#include <vector>

std::ostream & operator<<(std::ostream & cout,
                          const std::vector< std::vector< int > > & board)
{
    int n = board.size();
    for (auto && row: board)
    {
        for (int i = 0; i < n; ++i) std::cout << "+-";
        std::cout << '+' << '\n';
        std::cout << '|';
        for (auto && e: row)
        {
            if (e == -1) std::cout << " |";
            else std::cout << 'Q' << '|';
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; ++i) std::cout << "+-";
    std::cout << '+' << '\n';
    return cout;
}

bool nqueens(std::vector< int > & solution, std::vector< std::vector< int > > & board)
{
    if (solution.size() == board.size())
    {
        return true;
    }
    else
    {
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector< int > solution;
    std::vector< std::vector< int > > board(n, std::vector< int >(n, -1));
    std::cout << board << '\n';
    
    bool b = nqueens(solution, board);

    if (b)
    {
        std::cout << "success\n";
    }
    else
    {
        std::cout << "failure\n";
    }
    
}
