#ifndef MAT_H
#define MAT_H

#include <iostream>

class Mat
{
  public:
    Mat(int, int);
    ~Mat();
    int nrows() const;
    int ncols() const;
    double operator()(int, int) const;
  private:
    int nrows_;
    int ncols_;
    double * p_;
};

std::ostream & operator<<(std::ostream &, const Mat &);

#endif
