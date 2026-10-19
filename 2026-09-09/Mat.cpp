// file Mat.cpp

#include <iostream>
#include "Mat.h"

Mat::~Mat()
{
    delete[] p_;
}

Mat & Mat::operator=(const Mat & N)
{
    if (this != &N)
    {
        nrows_ = N.nrows_;
        ncols_ = N.ncols_;
        delete[] p_;
        p_ = new int[N.nrows_ * N.ncols_];
        for (int i = 0; i < N.nrows_ * N.ncols_; ++i)
        {
            p_[i] = N.p_[i];
        }
    }
    return (*this);
}

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

Mat & Mat::operator+=(const Mat & N)
{
    for (int i = 0; i < nrows_ * ncols_; ++i)
    {
        p_[i] += N.p_[i];
    }
    return (*this);
}

Mat Mat::operator+(const Mat & N) const
{
    return (Mat(*this) += N);
}

Mat Mat::operator*(int c) const
{
    Mat ret(*this);
    for (int i = 0; i < nrows_ * ncols_; ++i)
    {
        ret.p_[i] = c * p_[i];
    }
    return ret;
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
