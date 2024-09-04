#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  public:
    Matrix(int nrows, int ncols)
        : nrows_(nrows),
        ncols_(ncols),
        p_(new int[nrows * ncols])
    {}
    Matrix(const Matrix & m)
        : nrows_(m.nrows_),
          ncols_(m.ncols_),
          p_(new int[m.nrows_ * m.ncols_])
    {
        for (int i = 0; i < nrows_ * ncols_)
        {
            p_[i] = *(m.p_ + i); 
        }
    }
    ~Matrix()
    {
        delete [] p_;
    }
    operator=(
  private:
    int nrows_;
    int ncols_;
    int * p_;    
};

#endif
