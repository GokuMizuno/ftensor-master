#include "tensor.hpp"
#include <tuple>

std::tuple<double, double, double> tensor5()
{
  Tensor1<double, 3> y(0, 1, 2);
  Tensor1<double, 3> a1(2, 3, 4);
  Tensor1<double, 3> a2(5, 6, 7);
  Tensor1<double, 3> a3(8, 9, 10);
  Tensor1<double, 3> a4(11, 12, 13);
  Tensor1<double, 3> a5(14, 15, 16);

  for(int ii = 0; ii < 100000000; ii++)
    {
      func5(y, a1, a2, a3, a4, a5);
    }
  return std::make_tuple(y(0), y(1), y(2));
}
