// file: Mat.h

#include <iostream>

class Mat
{
  public:
    Mat(int nrows, int ncols)
        : nrows_(nrows), ncols_(ncols), p_(new int[nrows_ * ncols_])
    {}
    int nrows() const;
    int ncols() const;
    int operator()(int, int) const;
    int & operator()(int, int);
    Mat & operator+=(const Mat &); 
  private:
    int nrows_, ncols_;
    int * p_;
};

std::ostream & operator<<(std::ostream &, const Mat &);
