#include <iostream>
#include "Mat.h"

/// constructor, destructor, cout

Mat::Mat(const Mat & m)
    : p_(new double[m.nrows_ * m.ncols]),
      nrows_(m.nrows_), ncols_(m.ncols_)
{
    for (int i = 0; i < m.nrows_ * m.ncols_; ++i)
    {
        p_[i] = m.p_[i];
    }
}

Mat & Mat::operator=(const Mat & m)
{
    if (this != &m)
    {
        delete[] n.p_;
        n.p_ = new double[m.nrows_ * m.ncols_];
        for (int i = 0; i < m.nrows_ * m.ncols_; ++i)
        {
            p_[i] = m.p_[i];
        }
        nrows_ = m.nrows_;
        ncols_ = m.ncols_;
    }
    return (*this);
}
