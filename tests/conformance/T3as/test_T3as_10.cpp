#include "../../../src/FTensor.hpp"
#include "../test_for_zero.hpp"
#include <iostream>
using namespace FTensor;
using namespace std;

void test_T3as_10(const Tensor1<double, 3> &t1_2,
                  const Tensor2<double, 3, 3> &t2_2,
                  const Tensor3_antisymmetric<double, 3, 3> &t3as_2)
{
  Index<'i', 3> i;
  Index<'j', 3> j;
  Index<'k', 3> k;

  Number<0> N0;
  Number<1> N1;
  Number<2> N2;

  test_for_zero(t3as_2(i, j, k) * (t2_2(i, k) * t1_2(j))
                  - (t3as_2(0, 1, 0) * t2_2(0, 0) * t1_2(1)
                     + t3as_2(1, 1, 0) * t2_2(1, 0) * t1_2(1)
                     + t3as_2(2, 1, 0) * t2_2(2, 0) * t1_2(1)
                     + t3as_2(0, 2, 0) * t2_2(0, 0) * t1_2(2)
                     + t3as_2(1, 2, 0) * t2_2(1, 0) * t1_2(2)
                     + t3as_2(2, 2, 0) * t2_2(2, 0) * t1_2(2)
                     + t3as_2(0, 0, 1) * t2_2(0, 1) * t1_2(0)
                     + t3as_2(1, 0, 1) * t2_2(1, 1) * t1_2(0)
                     + t3as_2(2, 0, 1) * t2_2(2, 1) * t1_2(0)
                     + t3as_2(0, 2, 1) * t2_2(0, 1) * t1_2(2)
                     + t3as_2(1, 2, 1) * t2_2(1, 1) * t1_2(2)
                     + t3as_2(2, 2, 1) * t2_2(2, 1) * t1_2(2)
                     + t3as_2(0, 0, 2) * t2_2(0, 2) * t1_2(0)
                     + t3as_2(1, 0, 2) * t2_2(1, 2) * t1_2(0)
                     + t3as_2(2, 0, 2) * t2_2(2, 2) * t1_2(0)
                     + t3as_2(0, 1, 2) * t2_2(0, 2) * t1_2(1)
                     + t3as_2(1, 1, 2) * t2_2(1, 2) * t1_2(1)
                     + t3as_2(2, 1, 2) * t2_2(2, 2) * t1_2(1)),
                "T3as(i,j,k)*T3dg(i,k,j)");
  test_for_zero((t2_2(i, k) * t1_2(j) * t3as_2(i, j, k))
                  - (t3as_2(0, 1, 0) * t2_2(0, 0) * t1_2(1)
                     + t3as_2(1, 1, 0) * t2_2(1, 0) * t1_2(1)
                     + t3as_2(2, 1, 0) * t2_2(2, 0) * t1_2(1)
                     + t3as_2(0, 2, 0) * t2_2(0, 0) * t1_2(2)
                     + t3as_2(1, 2, 0) * t2_2(1, 0) * t1_2(2)
                     + t3as_2(2, 2, 0) * t2_2(2, 0) * t1_2(2)
                     + t3as_2(0, 0, 1) * t2_2(0, 1) * t1_2(0)
                     + t3as_2(1, 0, 1) * t2_2(1, 1) * t1_2(0)
                     + t3as_2(2, 0, 1) * t2_2(2, 1) * t1_2(0)
                     + t3as_2(0, 2, 1) * t2_2(0, 1) * t1_2(2)
                     + t3as_2(1, 2, 1) * t2_2(1, 1) * t1_2(2)
                     + t3as_2(2, 2, 1) * t2_2(2, 1) * t1_2(2)
                     + t3as_2(0, 0, 2) * t2_2(0, 2) * t1_2(0)
                     + t3as_2(1, 0, 2) * t2_2(1, 2) * t1_2(0)
                     + t3as_2(2, 0, 2) * t2_2(2, 2) * t1_2(0)
                     + t3as_2(0, 1, 2) * t2_2(0, 2) * t1_2(1)
                     + t3as_2(1, 1, 2) * t2_2(1, 2) * t1_2(1)
                     + t3as_2(2, 1, 2) * t2_2(2, 2) * t1_2(1)),
                "T3dg(i,k,j)*T3as(i,j,k)");
}
