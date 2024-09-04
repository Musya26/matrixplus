#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(test_constructor, test_2) {
  S21Matrix m(3, 3);
  ASSERT_EQ(m(2, 2), 0);
}

TEST(test_constructor, test_3) {
  S21Matrix m(3, 3);
  m(0, 0) = 10;
  S21Matrix tmp(m);
  ASSERT_EQ(tmp(0, 0), 10);
 
}

TEST(test_constructor, test_4) {
  S21Matrix m(3, 3);
  m(2, 2) = 4;
  S21Matrix ptr = m;
  ASSERT_EQ(ptr(2, 2), 4);

}

TEST(test_eq, eq_matrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333335;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = -3;

  S21Matrix B(2, 2);
  B(0, 0) = 3.33333356;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = -3;

  ASSERT_EQ(A.EqMatrix(B), 1);

}

TEST(test_eq, eq_matrix_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.33333357;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = -3;

  S21Matrix B(2, 2);
  B(0, 0) = 3.33333356;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = -3;

  ASSERT_EQ(A.EqMatrix(B), 1);
}

TEST(test_eq, eq_matrix_3) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.0;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = -3;

  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = -3;

  ASSERT_EQ(A.EqMatrix(B), 0);
}

TEST(test_eq, eq_matrix_4) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(2, 2);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333335;

  ASSERT_EQ(A.EqMatrix(B), 0);
}

TEST(test_eq, eq_matrix_5) {
  S21Matrix A(2, 2);
  S21Matrix B(3, 3);

  ASSERT_EQ(A.EqMatrix(B), 0);
}

TEST(test_sum, sum_matrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(2, 2);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333334;

  S21Matrix C(2, 2);
  C(0, 0) = 6.6666666;
  C(0, 1) = -10;
  C(1, 0) = 12;
  C(1, 1) = 6.6666668;

  A.SumMatrix(B);
  bool result = A.EqMatrix(C);

  ASSERT_EQ(result, 1);
}

TEST(test_sum, sum_matrix_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 0;
  A(0, 1) = 0;
  A(1, 0) = 0;
  A(1, 1) = 0;

  S21Matrix B(2, 2);
  B(0, 0) = 0;
  B(0, 1) = 0;
  B(1, 0) = 0;
  B(1, 1) = 0;

  S21Matrix C(2, 2);
  C(0, 0) = 0;
  C(0, 1) = 0;
  C(1, 0) = 0;
  C(1, 1) = 0;

  A.SumMatrix(B);
  bool result = A.EqMatrix(C);

  ASSERT_EQ(result, 1);
}

TEST(test_sum, sum_matrix_3) {
  S21Matrix A(4, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;

  S21Matrix B(4, 4);

  B(0, 0) = 8;
  B(0, 1) = 8;
  B(0, 2) = 3;
  B(0, 3) = 5;
  B(1, 0) = -7;
  B(1, 1) = 7;
  B(1, 2) = 1;
  B(1, 3) = 1;
  B(2, 0) = 7;
  B(2, 1) = 3;
  B(2, 2) = 4;
  B(2, 3) = -4;
  B(3, 0) = 10;
  B(3, 1) = 3;
  B(3, 2) = 9;
  B(3, 3) = -3;

  S21Matrix C(4, 4);

  C(0, 0) = 10;
  C(0, 1) = 13;
  C(0, 2) = 10;
  C(0, 3) = 1;
  C(1, 0) = -1;
  C(1, 1) = 10;
  C(1, 2) = 5;
  C(1, 3) = 15;
  C(2, 0) = 12;
  C(2, 1) = 1;
  C(2, 2) = 1;
  C(2, 3) = -5;
  C(3, 0) = 20;
  C(3, 1) = 6;
  C(3, 2) = 18;
  C(3, 3) = -6;

  A.SumMatrix(B);
  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

  // A.~S21Matrix();
  // B.~S21Matrix();
  // C.~S21Matrix();
}

TEST(test_sum, sum_matrix_4) {
  S21Matrix A(2, 2);

  A(0, 0) = 2.987654;
  A(0, 1) = -5.3456;
  A(1, 0) = 6.23;
  A(1, 1) = -3.9292;

  S21Matrix B(2, 2);

  B(0, 0) = 4.838;
  B(0, 1) = 8.0987;
  B(1, 0) = -8;
  B(1, 1) = -0.921;

  S21Matrix C(2, 2);

  C(0, 0) = 7.825654;
  C(0, 1) = 2.7531;
  C(1, 0) = -1.77;
  C(1, 1) = -4.8502;

  A.SumMatrix(B);
  ASSERT_EQ(A.EqMatrix(C), 1);

}

TEST(test_sum, sum_matrix_5) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(3, 3);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333334;

  bool catch_ex = false;

  try {
    A.SumMatrix(B);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_sub, sub_matrix_1) {
  S21Matrix A(2, 2);

  A(0, 0) = 10;
  A(0, 1) = 10;
  A(1, 0) = 10;
  A(1, 1) = 10;

  S21Matrix B(2, 2);

  B(0, 0) = 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;

  S21Matrix C(2, 2);

  C(0, 0) = 9;
  C(0, 1) = 9;
  C(1, 0) = 9;
  C(1, 1) = 9;

  A.SubMatrix(B);

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_sub, sub_matrix_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.987654;
  A(0, 1) = -5.3456;
  A(1, 0) = 6.23;
  A(1, 1) = -3.9292;

  S21Matrix B(2, 2);
  B(0, 0) = 4.838;
  B(0, 1) = 8.0987;
  B(1, 0) = -8;
  B(1, 1) = -0.921;

  S21Matrix C(2, 2);
  C(0, 0) = -1.850346;
  C(0, 1) = -13.4443;
  C(1, 0) = 14.23;
  C(1, 1) = -3.0082;

  A.SubMatrix(B);

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_sub, sub_matrix_3) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(3, 3);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333334;

  bool catch_ex = false;

  try {
    A.SubMatrix(B);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_mul, mul_matrix_1) {
  S21Matrix A(5, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(5, 4);
  B(0, 0) = 4;
  B(0, 1) = 10;
  B(0, 2) = 14;
  B(0, 3) = -8;
  B(1, 0) = 12;
  B(1, 1) = 6;
  B(1, 2) = 8;
  B(1, 3) = 28;
  B(2, 0) = 10;
  B(2, 1) = -4;
  B(2, 2) = -6;
  B(2, 3) = -2;
  B(3, 0) = 20;
  B(3, 1) = 6;
  B(3, 2) = 18;
  B(3, 3) = -6;
  B(4, 0) = -6;
  B(4, 1) = 6;
  B(4, 2) = 2;
  B(4, 3) = 10;

  A.MulNumber(2);

  bool result = A.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_mul, mul_matrix_2) {
  S21Matrix A(5, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(5, 4);
  B(0, 0) = 2 * 2.238;
  B(0, 1) = 5 * 2.238;
  B(0, 2) = 7 * 2.238;
  B(0, 3) = -4 * 2.238;
  B(1, 0) = 6 * 2.238;
  B(1, 1) = 3 * 2.238;
  B(1, 2) = 4 * 2.238;
  B(1, 3) = 14 * 2.238;
  B(2, 0) = 5 * 2.238;
  B(2, 1) = -2 * 2.238;
  B(2, 2) = -3 * 2.238;
  B(2, 3) = -1 * 2.238;
  B(3, 0) = 10 * 2.238;
  B(3, 1) = 3 * 2.238;
  B(3, 2) = 9 * 2.238;
  B(3, 3) = -3 * 2.238;
  B(4, 0) = -3 * 2.238;
  B(4, 1) = 3 * 2.238;
  B(4, 2) = 1 * 2.238;
  B(4, 3) = 5 * 2.238;

  A.MulNumber(2.238);
  bool result = A.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_mul_matrixs, mul_matrix_1) {
  S21Matrix A(5, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(4, 4);
  B(0, 0) = 8;
  B(0, 1) = 8;
  B(0, 2) = 3;
  B(0, 3) = 5;
  B(1, 0) = -7;
  B(1, 1) = 7;
  B(1, 2) = 1;
  B(1, 3) = 1;
  B(2, 0) = 7;
  B(2, 1) = 3;
  B(2, 2) = 4;
  B(2, 3) = -4;
  B(3, 0) = 10;
  B(3, 1) = 3;
  B(3, 2) = 9;
  B(3, 3) = -3;

  S21Matrix C(5, 4);
  C(0, 0) = -10;
  C(0, 1) = 60;
  C(0, 2) = 3;
  C(0, 3) = -1;
  C(1, 0) = 195;
  C(1, 1) = 123;
  C(1, 2) = 163;
  C(1, 3) = -25;
  C(2, 0) = 23;
  C(2, 1) = 14;
  C(2, 2) = -8;
  C(2, 3) = 38;
  C(3, 0) = 92;
  C(3, 1) = 119;
  C(3, 2) = 42;
  C(3, 3) = 26;
  C(4, 0) = 12;
  C(4, 1) = 15;
  C(4, 2) = 43;
  C(4, 3) = -31;

  A.MulMatrix(B);

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_over_sum, over_sum_matrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(2, 2);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333334;

  S21Matrix C(2, 2);
  C(0, 0) = 6.6666666;
  C(0, 1) = -10;
  C(1, 0) = 12;
  C(1, 1) = 6.6666668;

  S21Matrix D = A + B;
  bool result = D.EqMatrix(C);

  ASSERT_EQ(result, 1);
}

TEST(test_over_sum_eq, over_sum_eq_matrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3;

  S21Matrix B(2, 2);
  B(0, 0) = 3;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3;

  S21Matrix C(2, 2);
  C(0, 0) = 6;
  C(0, 1) = -10;
  C(1, 0) = 12;
  C(1, 1) = 6;

  A += B;

  bool result = A.EqMatrix(C);

  ASSERT_EQ(result, 1);
}

TEST(test_over_sum, over_sum_matrix_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333333;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3.3333334;

  S21Matrix B(3, 3);
  B(0, 0) = 3.3333333;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = 3.3333334;

  S21Matrix C;
  bool catch_ex = false;

  try {
    C = A + B;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_over_sub, over_sub_matrix_1) {
  S21Matrix A(2, 2);

  A(0, 0) = 10;
  A(0, 1) = 10;
  A(1, 0) = 10;
  A(1, 1) = 10;

  S21Matrix B(2, 2);

  B(0, 0) = 1;
  B(0, 1) = 1;
  B(1, 0) = 1;
  B(1, 1) = 1;

  S21Matrix C(2, 2);

  C(0, 0) = 9;
  C(0, 1) = 9;
  C(1, 0) = 9;
  C(1, 1) = 9;
  S21Matrix D = A - B;

  bool result = D.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_over_eq, over_eq_matrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3.3333335;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = -3;

  S21Matrix B(2, 2);
  B(0, 0) = 3.33333356;
  B(0, 1) = -5;
  B(1, 0) = 6;
  B(1, 1) = -3;

  ASSERT_EQ(A == B, 1);

}

TEST(test_over_mul_matrixs, mul_matrix_1) {
  S21Matrix A(5, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(4, 4);
  B(0, 0) = 8;
  B(0, 1) = 8;
  B(0, 2) = 3;
  B(0, 3) = 5;
  B(1, 0) = -7;
  B(1, 1) = 7;
  B(1, 2) = 1;
  B(1, 3) = 1;
  B(2, 0) = 7;
  B(2, 1) = 3;
  B(2, 2) = 4;
  B(2, 3) = -4;
  B(3, 0) = 10;
  B(3, 1) = 3;
  B(3, 2) = 9;
  B(3, 3) = -3;

  S21Matrix C(5, 4);
  C(0, 0) = -10;
  C(0, 1) = 60;
  C(0, 2) = 3;
  C(0, 3) = -1;
  C(1, 0) = 195;
  C(1, 1) = 123;
  C(1, 2) = 163;
  C(1, 3) = -25;
  C(2, 0) = 23;
  C(2, 1) = 14;
  C(2, 2) = -8;
  C(2, 3) = 38;
  C(3, 0) = 92;
  C(3, 1) = 119;
  C(3, 2) = 42;
  C(3, 3) = 26;
  C(4, 0) = 12;
  C(4, 1) = 15;
  C(4, 2) = 43;
  C(4, 3) = -31;

  A.MulMatrix(B);

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);
}

TEST(test_over_mul_matrixs, mul_matrix_2) {
  S21Matrix A(5, 4);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(4, 4);
  B(0, 0) = 8;
  B(0, 1) = 8;
  B(0, 2) = 3;
  B(0, 3) = 5;
  B(1, 0) = -7;
  B(1, 1) = 7;
  B(1, 2) = 1;
  B(1, 3) = 1;
  B(2, 0) = 7;
  B(2, 1) = 3;
  B(2, 2) = 4;
  B(2, 3) = -4;
  B(3, 0) = 10;
  B(3, 1) = 3;
  B(3, 2) = 9;
  B(3, 3) = -3;

  S21Matrix C(5, 4);
  C(0, 0) = -10;
  C(0, 1) = 60;
  C(0, 2) = 3;
  C(0, 3) = -1;
  C(1, 0) = 195;
  C(1, 1) = 123;
  C(1, 2) = 163;
  C(1, 3) = -25;
  C(2, 0) = 23;
  C(2, 1) = 14;
  C(2, 2) = -8;
  C(2, 3) = 38;
  C(3, 0) = 92;
  C(3, 1) = 119;
  C(3, 2) = 42;
  C(3, 3) = 26;
  C(4, 0) = 12;
  C(4, 1) = 15;
  C(4, 2) = 43;
  C(4, 3) = -31;

  A *= B;

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_transpose, transpose_1) {
  S21Matrix A(5, 4);

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(0, 3) = -4;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(1, 3) = 14;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  A(2, 3) = -1;
  A(3, 0) = 10;
  A(3, 1) = 3;
  A(3, 2) = 9;
  A(3, 3) = -3;
  A(4, 0) = -3;
  A(4, 1) = 3;
  A(4, 2) = 1;
  A(4, 3) = 5;

  S21Matrix B(4, 5);
  B(0, 0) = 2;
  B(0, 1) = 6;
  B(0, 2) = 5;
  B(0, 3) = 10;
  B(0, 4) = -3;
  B(1, 0) = 5;
  B(1, 1) = 3;
  B(1, 2) = -2;
  B(1, 3) = 3;
  B(1, 4) = 3;
  B(2, 0) = 7;
  B(2, 1) = 4;
  B(2, 2) = -3;
  B(2, 3) = 9;
  B(2, 4) = 1;
  B(3, 0) = -4;
  B(3, 1) = 14;
  B(3, 2) = -1;
  B(3, 3) = -3;
  B(3, 4) = 5;

  S21Matrix C = A.Transpose();

  bool result = C.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_create_minor_matrix, test_1) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  S21Matrix B(2, 2);
  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 8;
  B(1, 1) = 9;

  S21Matrix C = A.matrix_for_minor(0, 0);

  bool result = B.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_create_minor_matrix, test_2) {
  S21Matrix A(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  S21Matrix B(2, 2);

  B(0, 0) = 1;
  B(0, 1) = 3;
  B(1, 0) = 7;
  B(1, 1) = 9;

  S21Matrix C = A.matrix_for_minor(1, 1);

  bool result = B.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_determinant, test_1) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 5;
  A(1, 1) = 3;
  A(1, 2) = 2;
  A(2, 0) = -5;
  A(2, 1) = 3;
  A(2, 2) = 3;

  ASSERT_EQ(A.Determinant(), 43);
}

TEST(test_determinant, test_2) {
  S21Matrix A(4, 4);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 3;
  A(1, 0) = 5;
  A(1, 1) = 3;
  A(1, 2) = 2;
  A(1, 3) = 2;
  A(2, 0) = -5;
  A(2, 1) = 3;
  A(2, 2) = 3;
  A(2, 3) = 3;
  A(3, 0) = -12.12;
  A(3, 1) = 12.12;
  A(3, 2) = 2.12;
  A(3, 3) = -2.12;

  double res = fabs(A.Determinant()) - 182.32;
  ASSERT_EQ(res < 0.0000001, 1);
}

TEST(test_determinant, test_3) {
  S21Matrix A(2, 2);
  A(0, 0) = -12.12;
  A(0, 1) = -2.12;
  A(1, 0) = -2.12;
  A(1, 1) = -12.12;

  double res = fabs(A.Determinant()) - 142.4;
  ASSERT_EQ(res < 0.0000001, 1);

}

TEST(test_calc_complements, test_1) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  S21Matrix C(3, 3);
  C(0, 0) = 0;
  C(0, 1) = 10;
  C(0, 2) = -20;
  C(1, 0) = 4;
  C(1, 1) = -14;
  C(1, 2) = 8;
  C(2, 0) = -8;
  C(2, 1) = -2;
  C(2, 2) = 4;

  S21Matrix B = A.CalcComplements();

  bool result = B.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_calc_complements, test_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2;
  A(0, 1) = 4;
  A(1, 0) = 6;
  A(1, 1) = 3;

  S21Matrix C(2, 2);
  C(0, 0) = 3;
  C(0, 1) = -6;
  C(1, 0) = -4;
  C(1, 1) = 2;

  S21Matrix B = A.CalcComplements();

  bool result = B.EqMatrix(C);
  ASSERT_EQ(result, 1);

}

TEST(test_inverse_matrix, test_1) {
  S21Matrix A(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  S21Matrix B(3, 3);
  B(0, 0) = 1;
  B(0, 1) = -1;
  B(0, 2) = 1;
  B(1, 0) = -38;
  B(1, 1) = 41;
  B(1, 2) = -34;
  B(2, 0) = 27;
  B(2, 1) = -29;
  B(2, 2) = 24;

  S21Matrix C = A.InverseMatrix();

  bool result = C.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_inverse_matrix, test_2) {
  S21Matrix A(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 1.3;
  A(0, 2) = 0.7;
  A(1, 0) = -1;
  A(1, 1) = 0;
  A(1, 2) = 3;
  A(2, 0) = 0.3;
  A(2, 1) = -0.3;
  A(2, 2) = 2;

  S21Matrix B(3, 3);
  B(0, 0) = 45.0 / 289.0;
  B(0, 1) = -281.0 / 578.0;
  B(0, 2) = 195.0 / 289.0;
  B(1, 0) = 145.0 / 289.0;
  B(1, 1) = 379.0 / 578.0;
  B(1, 2) = -335.0 / 289.0;
  B(2, 0) = 15.0 / 289.0;
  B(2, 1) = 99.0 / 578.0;
  B(2, 2) = 65.0 / 289.0;

  S21Matrix C = A.InverseMatrix();

  bool result = C.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_inverse_matrix, test_3) {
  S21Matrix A(3, 3);
  A(0, 0) = 2.8;
  A(0, 1) = 1.3;
  A(0, 2) = 7.01;
  A(1, 0) = -1.03;
  A(1, 1) = -2.3;
  A(1, 2) = 3.01;
  A(2, 0) = 0;
  A(2, 1) = -3;
  A(2, 2) = 2;

  S21Matrix B(3, 3);
  B(0, 0) = 44300.0 / 367429.0;
  B(0, 1) = -236300.0 / 367429.0;
  B(0, 2) = 200360.0 / 367429.0;
  B(1, 0) = 20600.0 / 367429.0;
  B(1, 1) = 56000.0 / 367429.0;
  B(1, 2) = -156483.0 / 367429.0;
  B(2, 0) = 30900.0 / 367429.0;
  B(2, 1) = 84000.0 / 367429.0;
  B(2, 2) = -51010.0 / 367429.0;

  S21Matrix C = A.InverseMatrix();

  bool result = C.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

TEST(test_inverse_matrix, test_4) {
  S21Matrix A(1, 1);
  A(0, 0) = 777;

  S21Matrix B(1, 1);
  B(0, 0) = 1 / 777;

  S21Matrix C = A.InverseMatrix();

  bool result = C.EqMatrix(B);
  ASSERT_EQ(result, 1);

}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
