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
        int n = board.size();
        int c = solution.size(); // not base case: c < n - 1
        for (int r = 0; r < n; ++r)
        {
            // check if (r, c) is a valid move
            bool found_attack = false;
            // case attacking row
            for (int c0 = 0; c0 < c; ++c0)
            {
                if (board[r][c0] != -1)
                {
                    found_attack = true;
                    break;
                }
            }
            if (found_attack) continue;
            // case attacking diagonal
            for (int c0 = 0; c0 < c; ++c0)
            {
                for (int r0 = 0; r0 < n; ++r0)
                {
                    if (board[r0][c0] != -1)
                    {
                        int dr = r - r0;
                        int dc = c - c0;
                        if (dr == dc || dr == -dc)
                        {
                            found_attack = true;
                            break;
                        }
                    }
                }
                if (found_attack) break;
            }
            if (found_attack) continue;

            // this is a valid move: not attacking pairs
            solution.push_back(std::pair(r, c));
            board[r][c] = 1;
            bool b = nqueens(solution, board);
            if (b) return true;
            solution.pop_back();
            board[r][c] = -1;
        }
        return false;
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
        std::cout << board << '\n';
    }
    else
    {
        std::cout << "failure\n";
    }
    
}
