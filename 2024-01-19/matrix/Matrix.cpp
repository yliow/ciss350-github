// Matrix.cpp

#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new double[nrows * ncols])
{}

Matrix::~Matrix()
{
    delete [] p_;
}

Matrix::Matrix(const Matrix & m)
    : nrows_(m.nrows_), ncols_(m.ncols_),
      p_(new double[m.nrows_ * ncols_])
{
    for (int i = 0; i < nrows_ * ncols_; ++i)
    {
        p_[i] = m.p_[i];
    }
}

const Matrix & Matrix::operator=(const Matrix & m)
{
    if (this != &m)
    {
        delete [] p_;
        nrows_ = m.nrows_;
        ncols_ = m.ncols_;
        p_ = new double[nrows_ * ncols_];
        for (int i = 0; i < nrows_ * ncols_; ++i)
        {
            p_[i] = m.p_[i];
        }
    }
    return (*this);
}

int Matrix::nrows() const
{
    return nrows_;
}

int Matrix::ncols() const
{
    return ncols_;
}

double Matrix::operator()(int r, int c) const
{
    return p_[r * ncols_ + c];
}

double & Matrix::operator()(int r, int c)
{
    return p_[r * ncols_ + c];
}


std::ostream & operator<<(std::ostream & cout,
                          const Matrix & m)
{
    for (int r = 0; r < m.nrows(); ++r)
    {
        for (int c = 0; c < m.ncols(); ++c)
        {
            cout << m(r, c) << ' ';
        }
        cout << '\n';
    }
    return cout;
}
