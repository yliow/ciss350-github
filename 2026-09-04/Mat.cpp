// file Mat.cpp

#include <iostream>
#include "Mat.h"

int Mat::nrows() const
{
    return nrows_;
}

int Mat::ncols() const
{
    return ncols_;
}

int Mat::operator()(int r, int c) const
{
    return p_[ncols_ * r + c];
}

int & Mat::operator()(int r, int c)
{
    return p_[ncols_ * r + c];
}

Mat & Mat::operator+=(const Mat &)
{
    return (*this);
}

std::ostream & operator<<(std::ostream & cout, const Mat & M)
{
    for (int r = 0; r < M.nrows(); ++r)
    {
        cout << '[';
        for (int c = 0; c < M.ncols(); ++c)
        {
            cout << M(r, c);
            if (c < M.ncols() - 1)
                cout << ' ';
        }
        cout << "]\n";
    }
    return cout;
}
