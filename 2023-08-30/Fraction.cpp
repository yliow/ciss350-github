#include "Fraction.h"

int Fraction::n() const
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
    cout << f.n() << '/' << f.d();
    return cout;
}
