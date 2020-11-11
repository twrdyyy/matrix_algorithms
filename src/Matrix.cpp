#include "../lib/Matrix.hpp"
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <iostream>
#include <ostream>

template<typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _cols, const T& _initial) {
  data.resize(_rows);
  for (auto& col : data) {
    col.resize(_cols, _initial);
  }
  rows = _rows;
  cols = _cols;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) {
  data = matrix.data;
  rows = matrix.get_rows();
  cols = matrix.get_cols();
}

template<typename T>
Matrix<T>::~Matrix() {}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix) {
  if (&matrix == this)
    return *this;

  auto new_rows = matrix.get_rows();
  auto new_cols = matrix.get_cols();

  data.resize(new_rows);
  for (auto& col : data) {
    col.resize(new_cols);
  }

  for (unsigned i=0; i<new_rows; i++) {
    for (unsigned j=0; j<new_cols; j++) {
      data[i][j] = matrix(i, j);
    }
  }
  rows = new_rows;
  cols = new_cols;

  return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& matrix) {
  Matrix result(rows, cols, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] + matrix(i,j);
    }
  }

  return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& matrix) {
  auto rows = matrix.get_rows();
  auto cols = matrix.get_cols();

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      this->data[i][j] += matrix(i,j);
    }
  }

  return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& matrix) {
  auto rows = matrix.get_rows();
  auto cols = matrix.get_cols();
  Matrix result(rows, cols, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] - matrix(i,j);
    }
  }

  return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& matrix) {
  auto rows = matrix.get_rows();
  auto cols = matrix.get_cols();

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      this->data[i][j] -= matrix(i,j);
    }
  }

  return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() {
  Matrix result(cols, rows, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(j,i) = this->data[i][j];
    }
  }

  return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator+(const T& num) {
  Matrix result(rows, cols, 0.0);
  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] + num;
    }
  }

  return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& num) {
  Matrix result(rows, cols, 0.0);
  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] - num;
    }
  }

  return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& num) {
  Matrix result(rows, cols, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] * num;
    }
  }

  return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& num) {
  Matrix result(rows, cols, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[i][j] / num;
    }
  }

  return result;
}

template<typename T>
std::vector<T> Matrix<T>::diag_vec() {
  std::vector<T> result(rows, 0.0);
  for (unsigned i=0; i<rows; i++) {
    result[i] = this->data[i][i];
  }
  return result;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
  return this->data[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const {
  return this->data[row][col];
}

template<typename T>
std::vector<T> &Matrix<T>::operator()(const unsigned &row) {
    return this->data[row];
}

template<typename T>
unsigned Matrix<T>::get_rows() const {
  return this->rows;
}

template<typename T>
unsigned Matrix<T>::get_cols() const {
  return this->cols;
}

template<typename T>
Matrix<T> dot(Matrix<T> A, Matrix<T> B){
    auto n_rows = A.get_rows();
    auto n_cols = A.get_cols();

    Matrix<T> resutl (n_rows, n_cols);
    for(unsigned i = 0; i < n_rows; i++)
        for(unsigned j = 0; j < n_cols; j++)
            resutl(i, j) = A(i, j) * B(i ,j);
    return resutl;
}

template<typename T>
T dot_product(std::vector<T> &A, std::vector<T> &B){ 
    T result = A[0] * B[0];
    for (unsigned i = 1; i < A.size(); i++)
        result += A[i] * B[i];
    return result;
}

#define PRINT(OUT) \
    ( \
        std::cout << std::fixed << std::setprecision(5) << std::setw(3) << std::setfill(' ') << OUT << " "\
    )

template<typename T>
void Matrix<T>::print(){
    for (auto row : this->data) {
        std::cout << "| ";
        for(auto item : row)
            PRINT(item);
        std::cout << "|" << std::endl;
    }
}

#undef PRINT

/* example file */
/* 2 3 */ 
/* 1 2 3 */
/* 2 3 4 */
template <typename T>
Matrix<T> load_matrix_from_file(std::string file_path) {
    std::ifstream file(file_path);
    if(file.is_open()) { 
        int n, m;
        file >> n >> m;
        Matrix<T> result(n, m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file >> result(i, j);
            }
        }
        file.close();
        return result;
    }
    else std::cout << "Unable to open the file" << std::endl;
    Matrix<T> Err(1, 1, 0);
    return Err;
}
