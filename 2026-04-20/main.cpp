#include <iostream>
#include <vector>

bool nqueens_bt(int n, std::vector< int > & solution)
{
    if ((int) solution.size() == n)
    {
        return true;
    }
    else
    {
        int c = (int) solution.size();
        for (int r = 0; r < n; ++r)
        {
            bool is_valid = true;
            for (int c0 = 0; c0 < c; ++c0)
            {
                int r0 = solution[c0]; // the queen is at (r0, c0)
                // check if queen at (r0,c0) is attacking position (r,c)
                if (r == r0) // i.e. attacking hor
                {
                    is_valid = false;
                    break;
                }
                else if (r - r0 == c - c0 || r - r0 == -(c - c0))
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
            {
                solution.push_back(r);
                bool flag = nqueens_bt(n, solution);
                if (flag) return true;
                solution.pop_back();
            }
        }
        return false;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector< int > solution;
    bool flag = nqueens_bt(n, solution);
    if (flag)
    {
        std::cout << "SUCCESS\n";
        std::vector< std::vector< int > > m(n, std::vector< int >(n, 0));
        for (int c = 0; c < (int) solution.size(); ++c)
        {
            int r = solution[c];
            m[r][c] = 1;
        }
        std::cout << '\n';
        for (int c = 0; c < n; ++c)
        {
            std::cout << "+-";
        }
        std::cout << "+\n";
        for (int r = 0; r < n; ++r)
        {
            std::cout << '|';
            for (int c = 0; c < n; ++c)
            {
                std::cout << (m[r][c] == 1 ? 'Q' : ' ') << '|';
            }
            std::cout << '\n';
            for (int c = 0; c < n; ++c)
            {
                std::cout << "+-";
            }
            std::cout << "+\n";
        }
    }
    else
    {
        std::cout << "FAILURE\n";
    }
    return 0;
}
