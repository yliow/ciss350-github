#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  public:
    Matrix(int nrows, int ncols)
        : nrows_(nrows), ncols_(ncols)
    {
    }
  private:
    int nrows_, ncols_;
};
#endif
