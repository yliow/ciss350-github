#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
  public:
    Matrix(int nrows, int ncols)
        : nrows_(nrows), ncols_(ncols),
        p_(new double[nrows * ncols])
    {}
    int nrows() const
    {
        return nrows_;
    }
    int ncols() const
    {
        return ncols_;
    }
    void println()
    {
        for (int i = 0; i < nrows_ * ncols_; ++i)
        {
            std::cout << p_[i] << ' ';
        }
        std::cout << '\n';
    }
  private:
    int nrows_, ncols_;
    double * p_;
};
#endif
