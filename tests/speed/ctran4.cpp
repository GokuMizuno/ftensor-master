#include "ctran.hpp"
#include <tuple>

std::tuple<double,double,double> ctran4()
{
  double y[] = {0, 1, 2};
  double a1[] = {2, 3, 4};
  double a2[] = {5, 6, 7};
  double a3[] = {8, 9, 10};
  double a4[] = {11, 12, 13};

  for(int ii = 0; ii < 100000000; ii++)
    {
      func4(y, a1, a2, a3, a4);
    }
  return std::make_tuple(y[0],y[1],y[2]);
}
