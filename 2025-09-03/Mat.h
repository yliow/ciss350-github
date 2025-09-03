#ifndef MAT_H
#define MAT_H

class Mat
{
  public:
    Mat(int, int);
    ~Mat();
  private:
    int nrows_;
    int ncols_;
    double p_;
};

std::ostream & operator<<(std::stream &, const Mat &);

#endif
