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
    Matrix(const Matrix & m)
        : nrows_(m.nrows_), ncols_(m.ncols_),
        p_(new double[m.nrows_ * m.ncols_])
    {
        for (int i = 0; i < m.nrows_ * m.ncols_; ++i)
        {
            p_[i] = m.p_[i];
        }
    }
    ~Matrix()
    {
        std::cout << "Matrix::~Matrix() called ... "
                  << p_
                  << std::endl;
        delete[] p_;
    }
    const Matrix & operator=(const Matrix & m)
    {
        if (this != &m)
        {
            nrows_ = m.nrows_;
            ncols_ = m.ncols_;
            delete[] p_;
            p_ = new double[m.nrows_ * m.ncols_];
            for (int i = 0; i < m.nrows_ * m.ncols_; ++i)
            {
                p_[i] = m.p_[i];
            }
        }
        return (*this);
    }
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
    double operator()(int r, int c) const
    {
        return p_[c + ncols_ * r];        
    }
    double & operator()(int r, int c)
    {
        return p_[c + ncols_ * r];        
    }
    void println()
    {
        for (int r = 0; r < nrows_; ++r)
        {
            std::cout << '[';
            for (int c = 0; c < ncols_; ++c)
            {
                std::cout << get_value(r, c) << ' ';
            }
            std::cout << ']' << '\n';
        }
        std::cout << '\n';
    }
  private:
    int nrows_, ncols_;
    double * p_;
};

inline
std::ostream & operator<<(std::ostream & cout, const Matrix & m)
{
    for (int r = 0; r < m.nrows(); ++r)
    {
        std::cout << '[';
        for (int c = 0; c < m.ncols(); ++c)
        {
            std::cout << m(r, c) << ' ';
        }
        std::cout << ']' << '\n';
    }
    std::cout << '\n';

    return cout;
}

#endif