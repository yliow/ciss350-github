#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
  public:
    Fraction(int n, int d);
    int n() const;
    int d() const;
    void set_n(int n);
  private:
    int n_, d_; 
};

std::ostream & operator<<(std::ostream & cout,
                          const Fraction & f);

#endif
