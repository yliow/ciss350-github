// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  public:
    Matrix(int, int);
  private:
    int nrows_;
    int ncols_;
    double * p_;
};

#endif
