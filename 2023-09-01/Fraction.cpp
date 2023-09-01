#include "Fraction.h"

Fraction::Fraction(int n, int d)
    : n_(n), d_(d)
{}

void Fraction::set_n(int n)
{
    n_ = n;
}

int Fraction::n() const
{
    return n_;
}

int & Fraction::n() 
{
    return n_;
}

int Fraction::d() const
{
    return d_;
}

std::ostream & operator<<(std::ostream & cout,
                          const Fraction & f)
{
    if (f.d() == 0)
    {
        cout << "UNDEFINED";
    }
    else
    {
        if (f.d() == 1)
        {
            cout << f.n();
        }
        else
        {
            cout << f.n() << '/' << f.d();
        }
    }
    return cout;
}

Fraction Fraction::operator+(const Fraction & f)
{
   int n = n_ * f.d_ + d_ * f.n_;
   int d = d_ * f.d_;
   return Fraction(n, d);
}

