#ifndef MAT_H
#define MAT_H

class Mat
{
  public:
    // Constructor, destructor ...
    Mat(const Mat &);
    Mat & operator=(const Mat &);
  private:
    double * p_;
    int nrows_;
    int ncols_;
};

#endif
