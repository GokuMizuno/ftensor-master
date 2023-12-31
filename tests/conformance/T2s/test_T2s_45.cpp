#include "../../../src/FTensor.hpp"
#include "../test_for_zero.hpp"
#include <iostream>
using namespace FTensor;
using namespace std;

void test_T2s_45(const Tensor1<double, 3> &t1_2,
                 Tensor2_symmetric<double, 3> &t2s_1)
{
  Index<'i', 3> i;

  Number<0> N0;
  Number<1> N1;
  Number<2> N2;

  /* Tensor2_symmetric tests */

  /* Test of Number<> as an index. */

  t2s_1(N0, i) = t1_2(i);
  t2s_1(N0, i) += t1_2(i);
  test_for_zero(t2s_1(0, 0) - 2 * t1_2(0), "T2s+=(N,i)(0,0)");
  test_for_zero(t2s_1(0, 1) - 2 * t1_2(1), "T2s+=(N,i)(0,1)");
  test_for_zero(t2s_1(0, 2) - 2 * t1_2(2), "T2s+=(N,i)(0,2)");
  t2s_1(N0, i) -= t1_2(i);
  test_for_zero(t2s_1(0, 0) - t1_2(0), "T2s-=(N,i)(0,0)");
  test_for_zero(t2s_1(0, 1) - t1_2(1), "T2s-=(N,i)(0,1)");
  test_for_zero(t2s_1(0, 2) - t1_2(2), "T2s-=(N,i)(0,2)");

  t2s_1(N1, i) = t1_2(i);
  t2s_1(N1, i) += t1_2(i);
  test_for_zero(t2s_1(1, 0) - 2 * t1_2(0), "T2s+=(N,i)(1,0)");
  test_for_zero(t2s_1(1, 1) - 2 * t1_2(1), "T2s+=(N,i)(1,1)");
  test_for_zero(t2s_1(1, 2) - 2 * t1_2(2), "T2s+=(N,i)(1,2)");
  t2s_1(N1, i) -= t1_2(i);
  test_for_zero(t2s_1(1, 0) - t1_2(0), "T2s-=(N,i)(1,0)");
  test_for_zero(t2s_1(1, 1) - t1_2(1), "T2s-=(N,i)(1,1)");
  test_for_zero(t2s_1(1, 2) - t1_2(2), "T2s-=(N,i)(1,2)");

  t2s_1(N2, i) = t1_2(i);
  t2s_1(N2, i) += t1_2(i);
  test_for_zero(t2s_1(2, 0) - 2 * t1_2(0), "T2s+=(N,i)(2,0)");
  test_for_zero(t2s_1(2, 1) - 2 * t1_2(1), "T2s+=(N,i)(2,1)");
  test_for_zero(t2s_1(2, 2) - 2 * t1_2(2), "T2s+=(N,i)(2,2)");
  t2s_1(N2, i) -= t1_2(i);
  test_for_zero(t2s_1(2, 0) - t1_2(0), "T2s-=(N,i)(2,0)");
  test_for_zero(t2s_1(2, 1) - t1_2(1), "T2s-=(N,i)(2,1)");
  test_for_zero(t2s_1(2, 2) - t1_2(2), "T2s-=(N,i)(2,2)");
}
