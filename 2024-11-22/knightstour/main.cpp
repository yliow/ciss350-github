#include <iostream>
#include <vector>

typedef std::vector< std::vector< bool > > Board;
typedef std::vector< std::pair< int, int > > Solution;

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

bool bt_knights_tour(int n, Board & board, Solution & solution)
{
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
                                
    return 0;
}
