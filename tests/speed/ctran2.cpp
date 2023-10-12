#include "ctran.hpp"
#include <tuple>

std::tuple<double,double,double> ctran2()
{
  double y[] = {0, 1, 2};
  double a1[] = {2, 3, 4};
  double a2[] = {5, 6, 7};

  for(int ii = 0; ii < 100000000; ii++)
    {
      func2(y, a1, a2);
    }
  return std::make_tuple(y[0],y[1],y[2]);
}
