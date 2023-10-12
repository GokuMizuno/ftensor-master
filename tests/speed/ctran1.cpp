#include "ctran.hpp"
#include <tuple>

std::tuple<double,double,double> ctran1()
{
  double y[] = {0, 1, 2};
  double a1[] = {2, 3, 4};

  for(int ii = 0; ii < 100000000; ii++)
    {
      func1(y, a1);
    }
  return std::make_tuple(y[0],y[1],y[2]);
}
