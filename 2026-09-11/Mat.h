// file: Mat.h

#include <iostream>

class Mat
{
  public:
    Mat(int nrows, int ncols)
        : nrows_(nrows), ncols_(ncols), p_(new int[nrows_ * ncols_])
    {}
    Mat(const Mat & N)
        : nrows_(N.nrows_), ncols_(N.ncols_), p_(new int[N.nrows_ * N.ncols_])
    {
        for (int i = 0; i < N.nrows_ * N.ncols_; ++i)
        {
            p_[i] = N.p_[i];
        }
        // ALTERNATIVE: Using pointer iteration
        // int * p = N.p_;
        // int * q = p_;
        // for (int i = 0; i < N.nrows_ * N.ncols_: ++i)
        // {
        //     *q = *p; ++p; ++q;
        // }
    }
    ~Mat();
    Mat & operator=(const Mat &);
    int nrows() const;
    int ncols() const;
    int operator()(int, int) const;
    int & operator()(int, int);
    Mat & operator+=(const Mat &);
    Mat operator+(const Mat &) const;
    Mat operator*(int) const;
  private:
    int nrows_, ncols_;
    int * p_;
};
Mat operator*(int, const Mat &);

std::ostream & operator<<(std::ostream &, const Mat &);
