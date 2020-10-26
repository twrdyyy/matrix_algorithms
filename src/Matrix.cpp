#include "../lib/Matrix.hpp"

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
  Matrix result(rows, cols, 0.0);

  for (unsigned i=0; i<rows; i++) {
    for (unsigned j=0; j<cols; j++) {
      result(i,j) = this->data[j][i];
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
unsigned Matrix<T>::get_rows() const {
  return this->rows;
}

template<typename T>
unsigned Matrix<T>::get_cols() const {
  return this->cols;
}
