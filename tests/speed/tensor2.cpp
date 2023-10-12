#include "tensor.hpp"
#include <tuple>

std::tuple<double, double, double> tensor2()
{
  Tensor1<double, 3> y(0, 1, 2);
  Tensor1<double, 3> a1(2, 3, 4);
  Tensor1<double, 3> a2(5, 6, 7);

  for(int ii = 0; ii < 100000000; ii++)
    {
      func2(y, a1, a2);
    }
  return std::make_tuple(y(0), y(1), y(2));
}
