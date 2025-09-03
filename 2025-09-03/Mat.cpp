#include <iostream>
#include "Mat.h"


Mat::Mat(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new double[nrows * ncols])
{}

Mat::~Mat()
{
    delete[] p_;
}

std::ostream & operator<<(std::ostream & cout, const Mat & m)
{
    return cout;
}
