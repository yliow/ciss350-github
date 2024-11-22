#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector< std::vector< bool > > Board;
typedef std::vector< std::pair< int, int > > Solution;
typedef std::pair< int, int > Move;

std::ostream & operator<<(std::ostream & cout, const Board & board)
{
    int n = int(board.size());
    cout << '+';
    for (int i = 0; i < n; ++i) cout << "-";
    cout << "+\n";
    for (int r = 0; r < n; ++r)
    {
        cout << '|';
        for (int c = 0; c < n; ++c)
        {
            cout << board[r][c];
        }
        cout << "|\n";
    }
    cout << '+';
    for (int i = 0; i < n; ++i) cout << "-";
    cout << "+\n";
    return cout;
}

std::ostream & operator<<(std::ostream & cout, const Solution & solution)
{
    int n2 = int(solution.size());
    int n = sqrt(n2);
    std::vector< std::vector< int > > board(n, std::vector< int >(n, 0));
    for (int i = 0; i < n2; ++i)
    {
        Move pair = solution[i];
        int r = pair.first;
        int c = pair.second;
        std::cout << "r,c:" << r << ' ' << c << '\n';
        board[r][c] = i;
    }
    cout << '+';
    for (int i = 0; i < 3*n - 1; ++i) cout << "-";
    cout << "+\n";
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            cout << '|' << std::setw(2) << board[r][c];
        }
        cout << "|\n";
    }
    cout << '+';
    for (int i = 0; i < 3*n - 1; ++i) cout << "-";
    cout << "+\n";
    return cout;
}





bool bt_knights_tour(int n, Board & board, Solution & solution)
{
    if (solution.size() == n * n)
    {
        return true;
    }
    else
    {
        int n_ = int(solution.size());
        if (n_ == 0)
        {
            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    Move pair(r, c);
                    solution.push_back(pair);
                    board[r][c] = 1;
                    if (bt_knights_tour(n, board, solution))
                    {
                        return true;
                    }
                    board[r][c] = 0;
                    solution.pop_back();
                }
            }
            return false;
        }
        else
        {
            Move pair = solution.back();
            int r0 = pair.first;
            int c0 = pair.second;
            //std::cout << "r0,c0:" << r0 << ' ' << c0 << '\n';
            int drc[8][2] = {{+1,+2}, {-1,+2},
                             {-2,+1}, {-2,-1},
                             {-1,-2}, {+1,-2},
                             {+2,-1}, {+2,+1}};
            for (int i = 0; i < 8; ++i)
            {
                int r = r0 + drc[i][0];
                int c = c0 + drc[i][1];
                if ((0 <= r && r < n && 0 <= c && c < n)
                    && board[r][c] == 0)
                {
                    board[r][c] = 1;
                    Move pair(r, c);
                    solution.push_back(pair);
                    if (bt_knights_tour(n, board, solution))
                    {
                        return true;
                    }
                    board[r][c] = 0;
                    solution.pop_back();
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector< std::vector< bool > > board;
    board.resize(n);
    for (int i = 0; i < n; ++i)
    {
        board[i].resize(n);
    }
    std::cout << board << '\n';

    Solution solution;
    
    bool flag = bt_knights_tour(n, board, solution);
    std::cout << "flag:" << flag << '\n';
    if (flag)
    {
        std::cout << "success\n" << solution << '\n';
    }
    else
    {
        std::cout << "failure\n";
    }
    return 0;
}
