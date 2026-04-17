#include <iostream>
#include <vector>
#include <utility>

bool backtrack_knights_tour(int n,
                            std::vector< std::vector< int > > & m,
                            std::vector< std::pair< int, int > > & solution)
{
    if (solution.size() == n * n)
    {
        return true;
    }
    else
    {
        if (solution.size() == 0) // this si the first move
        {
            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    // put (r,c) into solution
                    std::pair< int, int > p(r, c);
                    solution.push_back(p);
                    m[r][c] = 1;
                    bool flag = backtrack_knights_tour(n, m, solution);
                    if (flag) return true;
                    // if received failure, undo my solution
                    solution.pop_back();
                    m[r][c] = 0;
                }
            }
            return false; // tried all options and cannot success
        }
        else // this is not the first move
        {
            int r = solution[solution.size() - 1].first;
            int c = solution[solution.size() - 1].second;
            int change[8][2] = {{-1,+2}, {-2,+1}, {-2,-1}, {-1,-2}, {+1,-2},
                                {+2,-1}, {+2,+1}, {+1,+2}};
            for (int i = 0; i < 8; ++i)
            {
                int r0 = r + change[i][0];
                int c0 = c + change[i][1];
            }
        }
        return false;
    }
}

int main()
{
    int n;
    std::cin >> n;

    // std::vector< int > a(5, 1);
    // std::cout << a.size() << ' ' << a[0] << '\n';
    std::vector< std::vector< int > > m(n, std::vector< int >(n, 0));
    // for (int r = 0; r < n; ++r)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         std::cout << m[r][c] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    
    // std::pair< int, int > p;
    // p.first = 0;
    // p.second = 2;

    std::vector< std::pair< int, int > > solution;
    
    bool flag = backtrack_knights_tour(n, m, solution);
    if (flag)
    {
        std::cout << "SUCCESS\n";
    }
    else
    {
        std::cout << "FAILURE\n";
    }
                                    
    return 0;
}
