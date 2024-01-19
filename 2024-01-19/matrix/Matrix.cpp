// Matrix.cpp

#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int nrows, int ncols)
    : nrows_(nrows), ncols_(ncols), p_(new double[nrows * ncols])
{}
