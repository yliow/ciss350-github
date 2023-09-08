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
    double get_value(int r, int c)
    {
        return p_[c + ncols_ * r];
    }
    void println()
    {
        for (int r = 0; r < nrows_; ++r)
        {
            for (int c = 0; r < ncols_; ++c)
            {
                std::cout << get_value(r, c);
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
  private:
    int nrows_, ncols_;
    double * p_;
};
#endif
