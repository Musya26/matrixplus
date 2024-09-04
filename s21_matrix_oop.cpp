#include "s21_matrix_oop.h"

#define SUCCESS 1
#define FAILURE 0

using namespace std;

S21Matrix::S21Matrix() {
  rows_ = 0, cols_ = 0;
  {
    matrix_ = new double*[rows_];
    matrix_[0] = new double[cols_];
  }
}  // базовый конструктор, вызывается сам при создании

S21Matrix::S21Matrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}  // Параметризированный конструктор с количеством строк и столбцов.

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[other.rows_];
  for (int i = 0; i < other.rows_; i++) {
    matrix_[i] = new double[other.cols_];
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}  // Конструктор копирования

S21Matrix::S21Matrix(S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  if (other.matrix_ == NULL) {
    throw std::invalid_argument("Incorrect matrix");
  }
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;

}  // Конструктор переноса

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] this->matrix_[i];
    matrix_[i] = NULL;
  }
  delete[] this->matrix_;
  matrix_ = NULL;
  rows_ = 0;
  cols_ = 0;
};

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix a(*this);
  a.SumMatrix(other);
  return a;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix a(*this);
  a.SubMatrix(other);
  return a;
}

S21Matrix S21Matrix::operator*(const double& num) const {
  S21Matrix a(*this);
  a.MulNumber(num);
  return a;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix a{*this};
  a.MulMatrix(other);
  return a;
}

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

void S21Matrix::operator*=(const double& num) { MulNumber(num); }

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return EqMatrix(other);
}

double& S21Matrix::operator()(int row, int col) const {
  if ((row >= rows_) || (col >= cols_) || (row < 0) || (col < 0))
    throw std::out_of_range("Beyond the matrix.");
  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) {
  if ((row >= rows_) || (col >= cols_) || (row < 0) || (col < 0))
    throw std::out_of_range("Beyond the matrix.");
  return matrix_[row][col];
}

void S21Matrix::Matrix_delete() {
  for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
  delete[] matrix_;
  matrix_ = nullptr;
}

void S21Matrix::SetRows(int new_rows) {
  if (new_rows != rows_) {
    double** new_matrix = new double*[new_rows];
    for (int i = 0; i < new_rows; ++i) {
      new_matrix[i] = new double[cols_];
      std::fill(new_matrix[i], new_matrix[i] + cols_, 0.0);
    }

    for (int i = 0; i < min(rows_, new_rows); ++i)
      for (int j = 0; j < cols_; ++j) new_matrix[i][j] = matrix_[i][j];

    Matrix_delete();
    matrix_ = new_matrix;
    rows_ = new_rows;
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols != cols_) {
    {
      double** new_matrix = new double*[rows_];
      for (int i = 0; i < rows_; ++i) {
        new_matrix[i] = new double[new_cols];
        std::fill(new_matrix[i], new_matrix[i] + cols_, 0.0);
      }

      for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < min(cols_, new_cols); ++j)
          new_matrix[i][j] = matrix_[i][j];

      Matrix_delete();
      matrix_ = new_matrix;
      cols_ = new_cols;
    }
  }
}

int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetCols() { return this->cols_; }

double** S21Matrix::GetMatrix() { return this->matrix_; }

void S21Matrix::SetMatrix(double** matrix) { this->matrix_ = matrix; }

int S21Matrix::Correct() {
  if ((this->matrix_ != nullptr) && (this->cols_ > 0) && (this->rows_ > 0))
    return 1;
  else
    return 0;
}

void S21Matrix::Remove() {
  for (int i = 0; i < this->cols_; i++)
    for (int j = 0; j < this->cols_; j++) this->matrix_[i][j] = 0;
}

S21Matrix S21Matrix::matrix_for_minor(int k, int n) {
  S21Matrix c(this->rows_ - 1, this->cols_ - 1);

  for (int i = 0, minor_row = 0; i < this->rows_; i++) {
    if (i != k) {
      for (int j = 0, minor_column = 0; j < this->cols_; j++) {
        if (j != n) {
          c.matrix_[minor_row][minor_column] = this->matrix_[i][j];
          minor_column++;
        }
      }
      minor_row++;
    }
  }
  return c;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix b(this->rows_, this->cols_);
  if (!this->Correct()) {
    throw std::invalid_argument("The matrix is not square");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix c = this->matrix_for_minor(i, j);
      b.matrix_[i][j] = pow(-1, i + j) * c.Determinant();
    }
  }
  return b;
}

double S21Matrix::Determinant() {  /////////а куда кидать этот детерминант??????
  double det;
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  if (this->cols_ == 1) det = this->matrix_[0][0];
  if (this->cols_ == 2)
    det = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[1][0] * this->matrix_[0][1];
  if (this->cols_ > 2) {
    S21Matrix C = this->CalcComplements();
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = this->matrix_for_minor(0, i);
      det += this->matrix_[0][i] * minor.Determinant() * pow(-1, i);
    }
  }
  return det;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (Determinant() == 0) {
    throw std::invalid_argument("The matrix is not square");
  }

  S21Matrix result_tmp_1 = CalcComplements();
  S21Matrix result_tmp_2 = result_tmp_1.Transpose();
  result_tmp_2.MulNumber(1 / Determinant());
  return result_tmp_2;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect matrix");
  }

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
    // }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect matrix");
  }
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  if ((this->matrix_ != nullptr) && (this->cols_ > 0) && (this->rows_ > 0)) {
    for (int i = 0; i < this->rows_; i++)
      for (int j = 0; j < this->cols_; j++)
        this->matrix_[i][j] = num * this->matrix_[i][j];
  }
}

void S21Matrix::create_matrix(int i, int j) {
  rows_ = i;
  cols_ = j;
  matrix_ = new double*[rows_]();
  for (int g = 0; g < rows_; g++) {
    matrix_[g] = new double[cols_]();
  }
}

void S21Matrix::free_memory() { this->~S21Matrix(); }

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Incorrect matrix");
  }
  int rw = this->rows_;
  int cl = this->cols_;
  S21Matrix tmp = *this;
  this->free_memory();
  this->create_matrix(rw, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      for (int k = 0; k < cl; k++) {
        matrix_[i][j] += tmp.matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix b(this->cols_, this->rows_);
  for (int i = 0; i < b.rows_; i++)
    for (int j = 0; j < b.cols_; j++) b.matrix_[i][j] = this->matrix_[j][i];
  return b;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool are_eqs = FAILURE;
  if ((this->cols_ == other.cols_) && (this->rows_ == other.rows_)) {
    are_eqs = SUCCESS;
    for (int i = 0; are_eqs && i < this->rows_; i++) {
      for (int j = 0; are_eqs && j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > S21_PREC)
          are_eqs = FAILURE;
      }
    }
  }
  return are_eqs;
}

