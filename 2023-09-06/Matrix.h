#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  public:
    Matrix(int nrows, int ncols)
        : nrows_(nrows), ncols_(ncols),
        p_(new double[nrows * ncols])

    {
    }
    int nrows() const
    {
        return nrows_;
    }
    int ncols() const
    {
        return ncols_;
    }
  private:
    int nrows_, ncols_;
    double * p_;
};
#endif
