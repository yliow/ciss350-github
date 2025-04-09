#include <iostream>
#include <iomanip>
#include <vector>

bool knightstour(int n,
                 std::vector< std::pair< int, int > > & solution,
                 std::vector< std::vector< int > > & board)
{
    if (solution.size() == n)
    {
        return true;
    }
    else
    {
        if (solution.size() == 0) // first step. pick anything
        {
            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    solution.push_back(std::pair< int, int >(r, c));
                    board[r][c] = 0;
                    bool b = knightstour(n, solution, board);
                    if (b) return true;
                    solution.pop_back();
                    board[r][c] = -1;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

std::ostream & operator<<(std::ostream & cout,
                          const std::vector< std::vector< int > > & board)
{
    int n = board.size();
    for (auto && row: board)
    {
        for (int i = 0; i < n; ++i) std::cout << "+--";
        std::cout << '+' << '\n';
        std::cout << '|';
        for (auto && e: row)
        {
            if (e == -1) std::cout << "  |";
            else std::cout << std::setw(2) << e << '|';
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; ++i) std::cout << "+--";
    std::cout << '+' << '\n';
    return cout;
}
                          
int main()
{
    int n;
    std::cin >> n;
    std::vector< std::pair< int, int > > solution;
    std::vector< std::vector< int > > board(n, std::vector< int >(n, -1));

    std::cout << board << '\n';
    
    bool b = knightstour(n, solution, board);
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
