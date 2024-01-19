// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  public:
    Matrix(int, int);
    ~Matrix();
    Matrix(const Matrix &);
    const Matrix & operator=(const Matrix &);
    int nrows() const;
    int ncols() const;
    double operator()(int, int) const;
    double & operator()(int, int);
  private:
    int nrows_;
    int ncols_;
    double * p_;
};

std::ostream & operator<<(std::ostream &, const Matrix &);

#endif
