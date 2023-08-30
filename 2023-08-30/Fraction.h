#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
  public:
    int n() const;
    int d() const;
  private:
    int n_, d_; 
};

std::ostream & operator<<(std::ostream & cout,
                          const Fraction & f);

#endif
