#include <iostream>
#include <iomanip>
#include <vector>

std::ostream & operator<<(std::ostream & cout,
                          const std::vector< std::vector< int > > & board);
bool knightstour(int n,
                 std::vector< std::pair< int, int > > & solution,
                 std::vector< std::vector< int > > & board)
{
    std::cout << board << '\n';
    if (solution.size() == n * n)
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
            int r = solution[solution.size() - 1].first;
            int c = solution[solution.size() - 1].second;
            int drc[8][2] = {{-1, +2}, {-2, +1}, {-2, -1}, {-1, -2},
                             {+1, -2}, {+2, -1}, {+2, +1}, {+1, +2}};
            for (int i = 0; i < 8; ++i)
            {
                int r1 = r + drc[i][0];
                int c1 = c + drc[i][1];
                if (0 <= r1 && r1 < n && 0 <= c1 && c1 < n)
                {
                    if (board[r1][c1] == -1)
                    {
                        solution.push_back(std::pair< int, int >(r1, c1));
                        board[r1][c1] = solution.size() - 1;
                        bool b = knightstour(n, solution, board);
                        if (b) return true;
                        std::cout << "ERROR ... try next option\n";
                        solution.pop_back();
                        board[r1][c1] = -1;
                    }
                }
            }
            std::cout << "ERROR ... backtrack\n";
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
        std::cout << board << '\n';
    }
    else
    {
        std::cout << "failure\n";
    }
    return 0;
}
