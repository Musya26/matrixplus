// using namespace std;
#ifndef S21MATRIX_SRC_MATRIX_H_
#define S21MATRIX_SRC_MATRIX_H_

#include <math.h>

#include <iostream>
#define S21_PREC 1e-7

#define SUCCESS 1
#define FAILURE 0

class S21Matrix {
 public:
  S21Matrix();  // базовый конструктор, вызывается сам при создании

  S21Matrix(int rows, int cols);  // Параметризированный конструктор с
                                  // количеством строк и столбцов.
  S21Matrix(const S21Matrix& other);  // Конструктор копирования

  S21Matrix(S21Matrix& other);  // Конструктор переноса

  ~S21Matrix();  // Destructor

  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
  void create_matrix(int i, int j);
  void free_memory();
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix matrix_for_minor(int k, int n);
  void Remove();
  int Correct();

  int GetRows();

  int GetCols();

  void Matrix_delete();
  double** GetMatrix();

  void SetMatrix(double** matrix);
  S21Matrix operator+(const S21Matrix& other) const;

  S21Matrix operator-(const S21Matrix& other) const;

  S21Matrix operator*(const double& num) const;

  S21Matrix operator*(const S21Matrix& other) const;

  void operator+=(const S21Matrix& other);

  void operator-=(const S21Matrix& other);

  void operator*=(const S21Matrix& other);

  void operator*=(const double& num);

  bool operator==(const S21Matrix& other) noexcept;

  double& operator()(int row, int col) const;

  double& operator()(int row, int col);

 private:  // поля открыты только самому классу либо дружественнным классам
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif //S21MATRIX_SRC_MATRIX_H_
