#include <iostream>
#include "Mat.h"

Mat::Mat(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new int[nrows * ncols])
{}

std::ostream & operator<<(std::ostream & cout, const Mat & m)
{
    cout << '{';
    for (int r = 0; r < m.nrows_; ++r)
    {
        cout << '{';
        for (int c = 0; c < m.ncols_; ++c)
        {
            cout << m.p_[r * m.ncols_ + c] << ", ";
        }
        cout << '}' << '\n';
    }
    cout << '}';
    return cout;
}
