#ifndef MAT_H
#define MAT_H

class MatSizeIncompatible
{};
    
class Mat
{
public:
    Mat(int nrows, int ncols);
    Mat(const Mat & m);
    ~Mat();
    int nrows() const;
    int ncols() const;
    int operator()(int r, int c) const;
    int & operator()(int r, int c);
    Mat & operator=(const Mat & m);
    Mat & operator+=(const Mat & n);
    Mat operator+(const Mat & n) const;
private:
    int nrows_;
    int ncols_;
    int * p_;
};

std::ostream & operator<<(std::ostream &, const Mat &);


#endif
