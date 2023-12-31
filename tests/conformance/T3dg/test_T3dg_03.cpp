#include "../../../src/FTensor.hpp"
#include "../test_for_zero.hpp"
#include <iostream>
using namespace FTensor;
using namespace std;

void test_T3dg_03(Tensor2_symmetric<double, 3> &t2s_1,
                  const Dg<double, 3, 3> &t3dg_2)
{
  Index<'i', 3> i;
  Index<'j', 3> j;

  Number<0> N0;
  Number<1> N1;
  Number<2> N2;

  t2s_1(i, j) = t3dg_2(i, j, N0);
  test_for_zero(t3dg_2(0, 0, 0) - t2s_1(0, 0), "T2s(i,j)=T3dg(i,j,N)(0,0,0)");
  test_for_zero(t3dg_2(0, 1, 0) - t2s_1(0, 1), "T2s(i,j)=T3dg(i,j,N)(0,0,1)");
  test_for_zero(t3dg_2(0, 2, 0) - t2s_1(0, 2), "T2s(i,j)=T3dg(i,j,N)(0,0,2)");
  test_for_zero(t3dg_2(1, 0, 0) - t2s_1(1, 0), "T2s(i,j)=T3dg(i,j,N)(0,1,0)");
  test_for_zero(t3dg_2(1, 1, 0) - t2s_1(1, 1), "T2s(i,j)=T3dg(i,j,N)(0,1,1)");
  test_for_zero(t3dg_2(1, 2, 0) - t2s_1(1, 2), "T2s(i,j)=T3dg(i,j,N)(0,1,2)");
  test_for_zero(t3dg_2(2, 0, 0) - t2s_1(2, 0), "T2s(i,j)=T3dg(i,j,N)(0,2,0)");
  test_for_zero(t3dg_2(2, 1, 0) - t2s_1(2, 1), "T2s(i,j)=T3dg(i,j,N)(0,2,1)");
  test_for_zero(t3dg_2(2, 2, 0) - t2s_1(2, 2), "T2s(i,j)=T3dg(i,j,N)(0,2,2)");

  t2s_1(i, j) = t3dg_2(i, j, N1);
  test_for_zero(t3dg_2(0, 0, 1) - t2s_1(0, 0), "T2s(i,j)=T3dg(i,j,N)(1,0,0)");
  test_for_zero(t3dg_2(0, 1, 1) - t2s_1(0, 1), "T2s(i,j)=T3dg(i,j,N)(1,0,1)");
  test_for_zero(t3dg_2(0, 2, 1) - t2s_1(0, 2), "T2s(i,j)=T3dg(i,j,N)(1,0,2)");
  test_for_zero(t3dg_2(1, 0, 1) - t2s_1(1, 0), "T2s(i,j)=T3dg(i,j,N)(1,1,0)");
  test_for_zero(t3dg_2(1, 1, 1) - t2s_1(1, 1), "T2s(i,j)=T3dg(i,j,N)(1,1,1)");
  test_for_zero(t3dg_2(1, 2, 1) - t2s_1(1, 2), "T2s(i,j)=T3dg(i,j,N)(1,1,2)");
  test_for_zero(t3dg_2(2, 0, 1) - t2s_1(2, 0), "T2s(i,j)=T3dg(i,j,N)(1,2,0)");
  test_for_zero(t3dg_2(2, 1, 1) - t2s_1(2, 1), "T2s(i,j)=T3dg(i,j,N)(1,2,1)");
  test_for_zero(t3dg_2(2, 2, 1) - t2s_1(2, 2), "T2s(i,j)=T3dg(i,j,N)(1,2,2)");

  t2s_1(i, j) = t3dg_2(i, j, N2);
  test_for_zero(t3dg_2(0, 0, 2) - t2s_1(0, 0), "T2s(i,j)=T3dg(i,j,N)(2,0,0)");
  test_for_zero(t3dg_2(0, 1, 2) - t2s_1(0, 1), "T2s(i,j)=T3dg(i,j,N)(2,0,1)");
  test_for_zero(t3dg_2(0, 2, 2) - t2s_1(0, 2), "T2s(i,j)=T3dg(i,j,N)(2,0,2)");
  test_for_zero(t3dg_2(1, 0, 2) - t2s_1(1, 0), "T2s(i,j)=T3dg(i,j,N)(2,1,0)");
  test_for_zero(t3dg_2(1, 1, 2) - t2s_1(1, 1), "T2s(i,j)=T3dg(i,j,N)(2,1,1)");
  test_for_zero(t3dg_2(1, 2, 2) - t2s_1(1, 2), "T2s(i,j)=T3dg(i,j,N)(2,1,2)");
  test_for_zero(t3dg_2(2, 0, 2) - t2s_1(2, 0), "T2s(i,j)=T3dg(i,j,N)(2,2,0)");
  test_for_zero(t3dg_2(2, 1, 2) - t2s_1(2, 1), "T2s(i,j)=T3dg(i,j,N)(2,2,1)");
  test_for_zero(t3dg_2(2, 2, 2) - t2s_1(2, 2), "T2s(i,j)=T3dg(i,j,N)(2,2,2)");
}
