#ifndef MAT_H
#define MAT_H

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
    void operator=(const Mat & m);
private:
    int nrows_;
    int ncols_;
    int * p_;
};

std::ostream & operator<<(std::ostream &, const Mat &);


#endif
