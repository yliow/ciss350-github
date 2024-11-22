#include <iostream>
#include <vector>

typedef std::vector< std::vector< bool > > Board;

std::ostream & operator<<(std::ostream & cout, const Board & board)
{
    int n = int(board.size());
    for (int r = 0; r < n; ++r)
    {
        cout << '|';
        for (int c = 0; c < n; ++c)
        {
            cout << board[r][c];
        }
        cout << "|\n";
    }
    return cout;
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
    
    //bool flag = bt_knights_tour(n, 
    return 0;
}
