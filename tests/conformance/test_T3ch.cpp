#include "../../src/FTensor.hpp"
#include "test_for_zero.hpp"
#include <iostream>
using namespace FTensor;
using namespace std;

void test_T3ch(const int &, Tensor0<double *> &, const Tensor0<double *> &,
               Tensor1<double, 3> &t1_1, const Tensor1<double, 3> &,
               Tensor2<double, 3, 3> &t2_1, const Tensor2<double, 3, 3> &,
               const Tensor2<double, 3, 3> &,
               Tensor2_symmetric<double, 3> &t2s_1,
               const Tensor2_symmetric<double, 3> &,
               const Tensor2_symmetric<double, 3> &, Dg<double, 3, 3> &,
               const Dg<double, 3, 3> &t3dg_2, const Dg<double, 3, 3> &,
               Christof<double, 3, 3> &t3ch_1,
               const Christof<double, 3, 3> &t3ch_2,
               const Christof<double, 3, 3> &)
{
  Index<'i', 3> i;
  Index<'j', 3> j;
  Index<'k', 3> k;

  Number<0> N0;
  Number<1> N1;
  Number<2> N2;

  /* Tensor3_ch tests */

  /* Number in one slot */

  t2s_1(i, j) = t3ch_1(N0, i, j);
  test_for_zero(t3ch_1(0, 0, 0) - t2s_1(0, 0), "T3ch(N,i,j)(0,0,0)");
  test_for_zero(t3ch_1(0, 0, 1) - t2s_1(0, 1), "T3ch(N,i,j)(0,0,1)");
  test_for_zero(t3ch_1(0, 0, 2) - t2s_1(0, 2), "T3ch(N,i,j)(0,0,2)");
  test_for_zero(t3ch_1(0, 1, 1) - t2s_1(1, 1), "T3ch(N,i,j)(0,1,1)");
  test_for_zero(t3ch_1(0, 1, 2) - t2s_1(1, 2), "T3ch(N,i,j)(0,1,2)");
  test_for_zero(t3ch_1(0, 2, 2) - t2s_1(2, 2), "T3ch(N,i,j)(0,2,2)");
  t2s_1(i, j) = t3ch_1(N1, i, j);
  test_for_zero(t3ch_1(1, 0, 0) - t2s_1(0, 0), "T3ch(N,i,j)(1,0,0)");
  test_for_zero(t3ch_1(1, 0, 1) - t2s_1(0, 1), "T3ch(N,i,j)(1,0,1)");
  test_for_zero(t3ch_1(1, 0, 2) - t2s_1(0, 2), "T3ch(N,i,j)(1,0,2)");
  test_for_zero(t3ch_1(1, 1, 1) - t2s_1(1, 1), "T3ch(N,i,j)(1,1,1)");
  test_for_zero(t3ch_1(1, 1, 2) - t2s_1(1, 2), "T3ch(N,i,j)(1,1,2)");
  test_for_zero(t3ch_1(1, 2, 2) - t2s_1(2, 2), "T3ch(N,i,j)(1,2,2)");
  t2s_1(i, j) = t3ch_1(N2, i, j);
  test_for_zero(t3ch_1(2, 0, 0) - t2s_1(0, 0), "T3ch(N,i,j)(2,0,0)");
  test_for_zero(t3ch_1(2, 0, 1) - t2s_1(0, 1), "T3ch(N,i,j)(2,0,1)");
  test_for_zero(t3ch_1(2, 0, 2) - t2s_1(0, 2), "T3ch(N,i,j)(2,0,2)");
  test_for_zero(t3ch_1(2, 1, 1) - t2s_1(1, 1), "T3ch(N,i,j)(2,1,1)");
  test_for_zero(t3ch_1(2, 1, 2) - t2s_1(1, 2), "T3ch(N,i,j)(2,1,2)");
  test_for_zero(t3ch_1(2, 2, 2) - t2s_1(2, 2), "T3ch(N,i,j)(2,2,2)");

  /* Number in two slots */

  t1_1(i) = t3ch_1(i, N0, N0);
  test_for_zero(t3ch_1(0, 0, 0) - t1_1(0), "T3ch(i,N,N)(0,0,0)");
  test_for_zero(t3ch_1(1, 0, 0) - t1_1(1), "T3ch(i,N,N)(1,0,0)");
  test_for_zero(t3ch_1(2, 0, 0) - t1_1(2), "T3ch(i,N,N)(2,0,0)");
  t1_1(i) = t3ch_1(i, N0, N1);
  test_for_zero(t3ch_1(0, 0, 1) - t1_1(0), "T3ch(i,N,N)(0,0,1)");
  test_for_zero(t3ch_1(1, 0, 1) - t1_1(1), "T3ch(i,N,N)(1,0,1)");
  test_for_zero(t3ch_1(2, 0, 1) - t1_1(2), "T3ch(i,N,N)(2,0,1)");
  t1_1(i) = t3ch_1(i, N0, N2);
  test_for_zero(t3ch_1(0, 0, 2) - t1_1(0), "T3ch(i,N,N)(0,0,2)");
  test_for_zero(t3ch_1(1, 0, 2) - t1_1(1), "T3ch(i,N,N)(1,0,2)");
  test_for_zero(t3ch_1(2, 0, 2) - t1_1(2), "T3ch(i,N,N)(2,0,2)");
  t1_1(i) = t3ch_1(i, N1, N0);
  test_for_zero(t3ch_1(0, 1, 0) - t1_1(0), "T3ch(i,N,N)(0,1,0)");
  test_for_zero(t3ch_1(1, 1, 0) - t1_1(1), "T3ch(i,N,N)(1,1,0)");
  test_for_zero(t3ch_1(2, 1, 0) - t1_1(2), "T3ch(i,N,N)(2,1,0)");
  t1_1(i) = t3ch_1(i, N1, N1);
  test_for_zero(t3ch_1(0, 1, 1) - t1_1(0), "T3ch(i,N,N)(0,1,1)");
  test_for_zero(t3ch_1(1, 1, 1) - t1_1(1), "T3ch(i,N,N)(1,1,1)");
  test_for_zero(t3ch_1(2, 1, 1) - t1_1(2), "T3ch(i,N,N)(2,1,1)");
  t1_1(i) = t3ch_1(i, N1, N2);
  test_for_zero(t3ch_1(0, 1, 2) - t1_1(0), "T3ch(i,N,N)(0,1,2)");
  test_for_zero(t3ch_1(1, 1, 2) - t1_1(1), "T3ch(i,N,N)(1,1,2)");
  test_for_zero(t3ch_1(2, 1, 2) - t1_1(2), "T3ch(i,N,N)(2,1,2)");
  t1_1(i) = t3ch_1(i, N2, N0);
  test_for_zero(t3ch_1(0, 2, 0) - t1_1(0), "T3ch(i,N,N)(0,2,0)");
  test_for_zero(t3ch_1(1, 2, 0) - t1_1(1), "T3ch(i,N,N)(1,2,0)");
  test_for_zero(t3ch_1(2, 2, 0) - t1_1(2), "T3ch(i,N,N)(2,2,0)");
  t1_1(i) = t3ch_1(i, N2, N1);
  test_for_zero(t3ch_1(0, 2, 1) - t1_1(0), "T3ch(i,N,N)(0,2,1)");
  test_for_zero(t3ch_1(1, 2, 1) - t1_1(1), "T3ch(i,N,N)(1,2,1)");
  test_for_zero(t3ch_1(2, 2, 1) - t1_1(2), "T3ch(i,N,N)(2,2,1)");
  t1_1(i) = t3ch_1(i, N2, N2);
  test_for_zero(t3ch_1(0, 2, 2) - t1_1(0), "T3ch(i,N,N)(0,2,2)");
  test_for_zero(t3ch_1(1, 2, 2) - t1_1(1), "T3ch(i,N,N)(1,2,2)");
  test_for_zero(t3ch_1(2, 2, 2) - t1_1(2), "T3ch(i,N,N)(2,2,2)");

  /* Now, test with actual numbers. */

  t2s_1(i, j) = t3ch_2(0, i, j);
  test_for_zero(t3ch_2(0, 0, 0) - t2s_1(0, 0), "T3ch(Num,i,j)(0,0,0)");
  test_for_zero(t3ch_2(0, 0, 1) - t2s_1(0, 1), "T3ch(Num,i,j)(0,0,1)");
  test_for_zero(t3ch_2(0, 0, 2) - t2s_1(0, 2), "T3ch(Num,i,j)(0,0,2)");
  test_for_zero(t3ch_2(0, 1, 0) - t2s_1(1, 0), "T3ch(Num,i,j)(0,1,0)");
  test_for_zero(t3ch_2(0, 1, 1) - t2s_1(1, 1), "T3ch(Num,i,j)(0,1,1)");
  test_for_zero(t3ch_2(0, 1, 2) - t2s_1(1, 2), "T3ch(Num,i,j)(0,1,2)");
  test_for_zero(t3ch_2(0, 2, 0) - t2s_1(2, 0), "T3ch(Num,i,j)(0,2,0)");
  test_for_zero(t3ch_2(0, 2, 1) - t2s_1(2, 1), "T3ch(Num,i,j)(0,2,1)");
  test_for_zero(t3ch_2(0, 2, 2) - t2s_1(2, 2), "T3ch(Num,i,j)(0,2,2)");

  t2s_1(i, j) = t3ch_2(1, i, j);
  test_for_zero(t3ch_2(1, 0, 0) - t2s_1(0, 0), "T3ch(Num,i,j)(1,0,0)");
  test_for_zero(t3ch_2(1, 0, 1) - t2s_1(0, 1), "T3ch(Num,i,j)(1,0,1)");
  test_for_zero(t3ch_2(1, 0, 2) - t2s_1(0, 2), "T3ch(Num,i,j)(1,0,2)");
  test_for_zero(t3ch_2(1, 1, 0) - t2s_1(1, 0), "T3ch(Num,i,j)(1,1,0)");
  test_for_zero(t3ch_2(1, 1, 1) - t2s_1(1, 1), "T3ch(Num,i,j)(1,1,1)");
  test_for_zero(t3ch_2(1, 1, 2) - t2s_1(1, 2), "T3ch(Num,i,j)(1,1,2)");
  test_for_zero(t3ch_2(1, 2, 0) - t2s_1(2, 0), "T3ch(Num,i,j)(1,2,0)");
  test_for_zero(t3ch_2(1, 2, 1) - t2s_1(2, 1), "T3ch(Num,i,j)(1,2,1)");
  test_for_zero(t3ch_2(1, 2, 2) - t2s_1(2, 2), "T3ch(Num,i,j)(1,2,2)");

  t2s_1(i, j) = t3ch_2(2, i, j);
  test_for_zero(t3ch_2(2, 0, 0) - t2s_1(0, 0), "T3ch(Num,i,j)(2,0,0)");
  test_for_zero(t3ch_2(2, 0, 1) - t2s_1(0, 1), "T3ch(Num,i,j)(2,0,1)");
  test_for_zero(t3ch_2(2, 0, 2) - t2s_1(0, 2), "T3ch(Num,i,j)(2,0,2)");
  test_for_zero(t3ch_2(2, 1, 0) - t2s_1(1, 0), "T3ch(Num,i,j)(2,1,0)");
  test_for_zero(t3ch_2(2, 1, 1) - t2s_1(1, 1), "T3ch(Num,i,j)(2,1,1)");
  test_for_zero(t3ch_2(2, 1, 2) - t2s_1(1, 2), "T3ch(Num,i,j)(2,1,2)");
  test_for_zero(t3ch_2(2, 2, 0) - t2s_1(2, 0), "T3ch(Num,i,j)(2,2,0)");
  test_for_zero(t3ch_2(2, 2, 1) - t2s_1(2, 1), "T3ch(Num,i,j)(2,2,1)");
  test_for_zero(t3ch_2(2, 2, 2) - t2s_1(2, 2), "T3ch(Num,i,j)(2,2,2)");

  t2_1(i, j) = t3ch_2(j, 0, i);
  test_for_zero(t3ch_2(0, 0, 0) - t2_1(0, 0), "T3ch(j,Num,i)(0,0,0)");
  test_for_zero(t3ch_2(1, 0, 0) - t2_1(0, 1), "T3ch(j,Num,i)(0,0,1)");
  test_for_zero(t3ch_2(2, 0, 0) - t2_1(0, 2), "T3ch(j,Num,i)(0,0,2)");
  test_for_zero(t3ch_2(0, 0, 1) - t2_1(1, 0), "T3ch(j,Num,i)(0,1,0)");
  test_for_zero(t3ch_2(1, 0, 1) - t2_1(1, 1), "T3ch(j,Num,i)(0,1,1)");
  test_for_zero(t3ch_2(2, 0, 1) - t2_1(1, 2), "T3ch(j,Num,i)(0,1,2)");
  test_for_zero(t3ch_2(0, 0, 2) - t2_1(2, 0), "T3ch(j,Num,i)(0,2,0)");
  test_for_zero(t3ch_2(1, 0, 2) - t2_1(2, 1), "T3ch(j,Num,i)(0,2,1)");
  test_for_zero(t3ch_2(2, 0, 2) - t2_1(2, 2), "T3ch(j,Num,i)(0,2,2)");

  t2_1(i, j) = t3ch_2(j, 1, i);
  test_for_zero(t3ch_2(0, 1, 0) - t2_1(0, 0), "T3ch(j,Num,i)(1,0,0)");
  test_for_zero(t3ch_2(1, 1, 0) - t2_1(0, 1), "T3ch(j,Num,i)(1,0,1)");
  test_for_zero(t3ch_2(2, 1, 0) - t2_1(0, 2), "T3ch(j,Num,i)(1,0,2)");
  test_for_zero(t3ch_2(0, 1, 1) - t2_1(1, 0), "T3ch(j,Num,i)(1,1,0)");
  test_for_zero(t3ch_2(1, 1, 1) - t2_1(1, 1), "T3ch(j,Num,i)(1,1,1)");
  test_for_zero(t3ch_2(2, 1, 1) - t2_1(1, 2), "T3ch(j,Num,i)(1,1,2)");
  test_for_zero(t3ch_2(0, 1, 2) - t2_1(2, 0), "T3ch(j,Num,i)(1,2,0)");
  test_for_zero(t3ch_2(1, 1, 2) - t2_1(2, 1), "T3ch(j,Num,i)(1,2,1)");
  test_for_zero(t3ch_2(2, 1, 2) - t2_1(2, 2), "T3ch(j,Num,i)(1,2,2)");

  t2_1(i, j) = t3ch_2(j, 2, i);
  test_for_zero(t3ch_2(0, 2, 0) - t2_1(0, 0), "T3ch(j,Num,i)(2,0,0)");
  test_for_zero(t3ch_2(1, 2, 0) - t2_1(0, 1), "T3ch(j,Num,i)(2,0,1)");
  test_for_zero(t3ch_2(2, 2, 0) - t2_1(0, 2), "T3ch(j,Num,i)(2,0,2)");
  test_for_zero(t3ch_2(0, 2, 1) - t2_1(1, 0), "T3ch(j,Num,i)(2,1,0)");
  test_for_zero(t3ch_2(1, 2, 1) - t2_1(1, 1), "T3ch(j,Num,i)(2,1,1)");
  test_for_zero(t3ch_2(2, 2, 1) - t2_1(1, 2), "T3ch(j,Num,i)(2,1,2)");
  test_for_zero(t3ch_2(0, 2, 2) - t2_1(2, 0), "T3ch(j,Num,i)(2,2,0)");
  test_for_zero(t3ch_2(1, 2, 2) - t2_1(2, 1), "T3ch(j,Num,i)(2,2,1)");
  test_for_zero(t3ch_2(2, 2, 2) - t2_1(2, 2), "T3ch(j,Num,i)(2,2,2)");

  t2_1(i, j) = t3ch_2(j, i, 0);
  test_for_zero(t3ch_2(0, 0, 0) - t2_1(0, 0), "T3ch(j,i,Num)(0,0,0)");
  test_for_zero(t3ch_2(1, 0, 0) - t2_1(0, 1), "T3ch(j,i,Num)(0,0,1)");
  test_for_zero(t3ch_2(2, 0, 0) - t2_1(0, 2), "T3ch(j,i,Num)(0,0,2)");
  test_for_zero(t3ch_2(0, 1, 0) - t2_1(1, 0), "T3ch(j,i,Num)(0,1,0)");
  test_for_zero(t3ch_2(1, 1, 0) - t2_1(1, 1), "T3ch(j,i,Num)(0,1,1)");
  test_for_zero(t3ch_2(2, 1, 0) - t2_1(1, 2), "T3ch(j,i,Num)(0,1,2)");
  test_for_zero(t3ch_2(0, 2, 0) - t2_1(2, 0), "T3ch(j,i,Num)(0,2,0)");
  test_for_zero(t3ch_2(1, 2, 0) - t2_1(2, 1), "T3ch(j,i,Num)(0,2,1)");
  test_for_zero(t3ch_2(2, 2, 0) - t2_1(2, 2), "T3ch(j,i,Num)(0,2,2)");

  t2_1(i, j) = t3ch_2(j, i, 1);
  test_for_zero(t3ch_2(0, 0, 1) - t2_1(0, 0), "T3ch(j,i,Num)(1,0,0)");
  test_for_zero(t3ch_2(1, 0, 1) - t2_1(0, 1), "T3ch(j,i,Num)(1,0,1)");
  test_for_zero(t3ch_2(2, 0, 1) - t2_1(0, 2), "T3ch(j,i,Num)(1,0,2)");
  test_for_zero(t3ch_2(0, 1, 1) - t2_1(1, 0), "T3ch(j,i,Num)(1,1,0)");
  test_for_zero(t3ch_2(1, 1, 1) - t2_1(1, 1), "T3ch(j,i,Num)(1,1,1)");
  test_for_zero(t3ch_2(2, 1, 1) - t2_1(1, 2), "T3ch(j,i,Num)(1,1,2)");
  test_for_zero(t3ch_2(0, 2, 1) - t2_1(2, 0), "T3ch(j,i,Num)(1,2,0)");
  test_for_zero(t3ch_2(1, 2, 1) - t2_1(2, 1), "T3ch(j,i,Num)(1,2,1)");
  test_for_zero(t3ch_2(2, 2, 1) - t2_1(2, 2), "T3ch(j,i,Num)(1,2,2)");

  t2_1(i, j) = t3ch_2(j, i, 2);
  test_for_zero(t3ch_2(0, 0, 2) - t2_1(0, 0), "T3ch(j,i,Num)(2,0,0)");
  test_for_zero(t3ch_2(1, 0, 2) - t2_1(0, 1), "T3ch(j,i,Num)(2,0,1)");
  test_for_zero(t3ch_2(2, 0, 2) - t2_1(0, 2), "T3ch(j,i,Num)(2,0,2)");
  test_for_zero(t3ch_2(0, 1, 2) - t2_1(1, 0), "T3ch(j,i,Num)(2,1,0)");
  test_for_zero(t3ch_2(1, 1, 2) - t2_1(1, 1), "T3ch(j,i,Num)(2,1,1)");
  test_for_zero(t3ch_2(2, 1, 2) - t2_1(1, 2), "T3ch(j,i,Num)(2,1,2)");
  test_for_zero(t3ch_2(0, 2, 2) - t2_1(2, 0), "T3ch(j,i,Num)(2,2,0)");
  test_for_zero(t3ch_2(1, 2, 2) - t2_1(2, 1), "T3ch(j,i,Num)(2,2,1)");
  test_for_zero(t3ch_2(2, 2, 2) - t2_1(2, 2), "T3ch(j,i,Num)(2,2,2)");

  /* Assignment to double */

  t3ch_1(i, j, k) = 10;
  test_for_zero(t3ch_1(0, 0, 0) - 10, "T3ch=T(0,0,0)");
  test_for_zero(t3ch_1(0, 0, 1) - 10, "T3ch=T(0,0,1)");
  test_for_zero(t3ch_1(0, 0, 2) - 10, "T3ch=T(0,0,2)");
  test_for_zero(t3ch_1(0, 1, 0) - 10, "T3ch=T(0,1,0)");
  test_for_zero(t3ch_1(0, 1, 1) - 10, "T3ch=T(0,1,1)");
  test_for_zero(t3ch_1(0, 1, 2) - 10, "T3ch=T(0,1,2)");
  test_for_zero(t3ch_1(0, 2, 0) - 10, "T3ch=T(0,2,0)");
  test_for_zero(t3ch_1(0, 2, 1) - 10, "T3ch=T(0,2,1)");
  test_for_zero(t3ch_1(0, 2, 2) - 10, "T3ch=T(0,2,2)");
  test_for_zero(t3ch_1(1, 0, 0) - 10, "T3ch=T(1,0,0)");
  test_for_zero(t3ch_1(1, 0, 1) - 10, "T3ch=T(1,0,1)");
  test_for_zero(t3ch_1(1, 0, 2) - 10, "T3ch=T(1,0,2)");
  test_for_zero(t3ch_1(1, 1, 0) - 10, "T3ch=T(1,1,0)");
  test_for_zero(t3ch_1(1, 1, 1) - 10, "T3ch=T(1,1,1)");
  test_for_zero(t3ch_1(1, 1, 2) - 10, "T3ch=T(1,1,2)");
  test_for_zero(t3ch_1(1, 2, 0) - 10, "T3ch=T(1,2,0)");
  test_for_zero(t3ch_1(1, 2, 1) - 10, "T3ch=T(1,2,1)");
  test_for_zero(t3ch_1(1, 2, 2) - 10, "T3ch=T(1,2,2)");
  test_for_zero(t3ch_1(2, 0, 0) - 10, "T3ch=T(2,0,0)");
  test_for_zero(t3ch_1(2, 0, 1) - 10, "T3ch=T(2,0,1)");
  test_for_zero(t3ch_1(2, 0, 2) - 10, "T3ch=T(2,0,2)");
  test_for_zero(t3ch_1(2, 1, 0) - 10, "T3ch=T(2,1,0)");
  test_for_zero(t3ch_1(2, 1, 1) - 10, "T3ch=T(2,1,1)");
  test_for_zero(t3ch_1(2, 1, 2) - 10, "T3ch=T(2,1,2)");
  test_for_zero(t3ch_1(2, 2, 0) - 10, "T3ch=T(2,2,0)");
  test_for_zero(t3ch_1(2, 2, 1) - 10, "T3ch=T(2,2,1)");
  test_for_zero(t3ch_1(2, 2, 2) - 10, "T3ch=T(2,2,2)");

  t3ch_1(i, j, k) = t3dg_2(j, k, i);
  test_for_zero(t3ch_1(0, 0, 0) - t3dg_2(0, 0, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,0,0)");
  test_for_zero(t3ch_1(0, 0, 1) - t3dg_2(0, 1, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,0,1)");
  test_for_zero(t3ch_1(0, 0, 2) - t3dg_2(0, 2, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,0,2)");
  test_for_zero(t3ch_1(0, 1, 0) - t3dg_2(1, 0, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,1,0)");
  test_for_zero(t3ch_1(0, 1, 1) - t3dg_2(1, 1, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,1,1)");
  test_for_zero(t3ch_1(0, 1, 2) - t3dg_2(1, 2, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,1,2)");
  test_for_zero(t3ch_1(0, 2, 0) - t3dg_2(2, 0, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,2,0)");
  test_for_zero(t3ch_1(0, 2, 1) - t3dg_2(2, 1, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,2,1)");
  test_for_zero(t3ch_1(0, 2, 2) - t3dg_2(2, 2, 0),
                "T3ch(i,j,k)=T3dg(j,k,i)(0,2,2)");
  test_for_zero(t3ch_1(1, 0, 0) - t3dg_2(0, 0, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,0,0)");
  test_for_zero(t3ch_1(1, 0, 1) - t3dg_2(0, 1, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,0,1)");
  test_for_zero(t3ch_1(1, 0, 2) - t3dg_2(0, 2, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,0,2)");
  test_for_zero(t3ch_1(1, 1, 0) - t3dg_2(1, 0, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,1,0)");
  test_for_zero(t3ch_1(1, 1, 1) - t3dg_2(1, 1, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,1,1)");
  test_for_zero(t3ch_1(1, 1, 2) - t3dg_2(1, 2, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,1,2)");
  test_for_zero(t3ch_1(1, 2, 0) - t3dg_2(2, 0, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,2,0)");
  test_for_zero(t3ch_1(1, 2, 1) - t3dg_2(2, 1, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,2,1)");
  test_for_zero(t3ch_1(1, 2, 2) - t3dg_2(2, 2, 1),
                "T3ch(i,j,k)=T3dg(j,k,i)(1,2,2)");
  test_for_zero(t3ch_1(2, 0, 0) - t3dg_2(0, 0, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,0,0)");
  test_for_zero(t3ch_1(2, 0, 1) - t3dg_2(0, 1, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,0,1)");
  test_for_zero(t3ch_1(2, 0, 2) - t3dg_2(0, 2, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,0,2)");
  test_for_zero(t3ch_1(2, 1, 0) - t3dg_2(1, 0, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,1,0)");
  test_for_zero(t3ch_1(2, 1, 1) - t3dg_2(1, 1, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,1,1)");
  test_for_zero(t3ch_1(2, 1, 2) - t3dg_2(1, 2, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,1,2)");
  test_for_zero(t3ch_1(2, 2, 0) - t3dg_2(2, 0, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,2,0)");
  test_for_zero(t3ch_1(2, 2, 1) - t3dg_2(2, 1, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,2,1)");
  test_for_zero(t3ch_1(2, 2, 2) - t3dg_2(2, 2, 2),
                "T3ch(i,j,k)=T3dg(j,k,i)(2,2,2)");

  t3ch_1(i, j, k) = t3ch_2(i, j, k);
  test_for_zero(t3ch_1(0, 0, 0) - t3ch_2(0, 0, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,0,0)");
  test_for_zero(t3ch_1(0, 0, 1) - t3ch_2(0, 0, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,0,1)");
  test_for_zero(t3ch_1(0, 0, 2) - t3ch_2(0, 0, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,0,2)");
  test_for_zero(t3ch_1(0, 1, 0) - t3ch_2(0, 1, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,1,0)");
  test_for_zero(t3ch_1(0, 1, 1) - t3ch_2(0, 1, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,1,1)");
  test_for_zero(t3ch_1(0, 1, 2) - t3ch_2(0, 1, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,1,2)");
  test_for_zero(t3ch_1(0, 2, 0) - t3ch_2(0, 2, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,2,0)");
  test_for_zero(t3ch_1(0, 2, 1) - t3ch_2(0, 2, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,2,1)");
  test_for_zero(t3ch_1(0, 2, 2) - t3ch_2(0, 2, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(0,2,2)");
  test_for_zero(t3ch_1(1, 0, 0) - t3ch_2(1, 0, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,0,0)");
  test_for_zero(t3ch_1(1, 0, 1) - t3ch_2(1, 0, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,0,1)");
  test_for_zero(t3ch_1(1, 0, 2) - t3ch_2(1, 0, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,0,2)");
  test_for_zero(t3ch_1(1, 1, 0) - t3ch_2(1, 1, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,1,0)");
  test_for_zero(t3ch_1(1, 1, 1) - t3ch_2(1, 1, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,1,1)");
  test_for_zero(t3ch_1(1, 1, 2) - t3ch_2(1, 1, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,1,2)");
  test_for_zero(t3ch_1(1, 2, 0) - t3ch_2(1, 2, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,2,0)");
  test_for_zero(t3ch_1(1, 2, 1) - t3ch_2(1, 2, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,2,1)");
  test_for_zero(t3ch_1(1, 2, 2) - t3ch_2(1, 2, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(1,2,2)");
  test_for_zero(t3ch_1(2, 0, 0) - t3ch_2(2, 0, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,0,0)");
  test_for_zero(t3ch_1(2, 0, 1) - t3ch_2(2, 0, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,0,1)");
  test_for_zero(t3ch_1(2, 0, 2) - t3ch_2(2, 0, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,0,2)");
  test_for_zero(t3ch_1(2, 1, 0) - t3ch_2(2, 1, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,1,0)");
  test_for_zero(t3ch_1(2, 1, 1) - t3ch_2(2, 1, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,1,1)");
  test_for_zero(t3ch_1(2, 1, 2) - t3ch_2(2, 1, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,1,2)");
  test_for_zero(t3ch_1(2, 2, 0) - t3ch_2(2, 2, 0),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,2,0)");
  test_for_zero(t3ch_1(2, 2, 1) - t3ch_2(2, 2, 1),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,2,1)");
  test_for_zero(t3ch_1(2, 2, 2) - t3ch_2(2, 2, 2),
                "T3ch(i,j,k)=T3ch(i,j,k)(2,2,2)");

  t1_1(i) = t3ch_1(i, j, j);
  test_for_zero(t1_1(0)
                  - (t3ch_1(0, 0, 0) + t3ch_1(0, 1, 1) + t3ch_1(0, 2, 2)),
                "t3ch(i,j,j)(0)");
  test_for_zero(t1_1(1)
                  - (t3ch_1(1, 0, 0) + t3ch_1(1, 1, 1) + t3ch_1(1, 2, 2)),
                "t3ch(i,j,j)(1)");
  test_for_zero(t1_1(2)
                  - (t3ch_1(2, 0, 0) + t3ch_1(2, 1, 1) + t3ch_1(2, 2, 2)),
                "t3ch(i,j,j)(2)");
  t1_1(i) = t3ch_1(j, i, j);
  test_for_zero(t1_1(0)
                  - (t3ch_1(0, 0, 0) + t3ch_1(1, 0, 1) + t3ch_1(2, 0, 2)),
                "t3ch(j,i,j)(0)");
  test_for_zero(t1_1(1)
                  - (t3ch_1(0, 1, 0) + t3ch_1(1, 1, 1) + t3ch_1(2, 1, 2)),
                "t3ch(j,i,j)(1)");
  test_for_zero(t1_1(2)
                  - (t3ch_1(0, 2, 0) + t3ch_1(1, 2, 1) + t3ch_1(2, 2, 2)),
                "t3ch(j,i,j)(2)");
  t1_1(i) = t3ch_1(j, j, i);
  test_for_zero(t1_1(0)
                  - (t3ch_1(0, 0, 0) + t3ch_1(1, 1, 0) + t3ch_1(2, 2, 0)),
                "t3ch(j,j,i)(0)");
  test_for_zero(t1_1(1)
                  - (t3ch_1(0, 0, 1) + t3ch_1(1, 1, 1) + t3ch_1(2, 2, 1)),
                "t3ch(j,j,i)(1)");
  test_for_zero(t1_1(2)
                  - (t3ch_1(0, 0, 2) + t3ch_1(1, 1, 2) + t3ch_1(2, 2, 2)),
                "t3ch(j,j,i)(2)");
}
