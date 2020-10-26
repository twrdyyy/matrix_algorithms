#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <typename T> class Matrix {
private:
  std::vector<std::vector<T> > data;
  unsigned rows;
  unsigned cols;

 public:
   Matrix(unsigned _rows, unsigned _cols, const T &_initial);
   Matrix(const Matrix<T> &matrix);
   virtual ~Matrix();

   Matrix<T> &operator=(const Matrix<T> &matrix);

   Matrix<T> operator+(const Matrix<T> &matrix);
   Matrix<T> &operator+=(const Matrix<T> &matrix);
   Matrix<T> operator-(const Matrix<T> &matrix);
   Matrix<T> &operator-=(const Matrix<T> &matrix);

   Matrix<T> operator+(const T &num);
   Matrix<T> operator-(const T &num);
   Matrix<T> operator*(const T& num);
   Matrix<T> operator/(const T& num);

   Matrix<T> transpose();
   std::vector<T> diag_vec();

   T &operator()(const unsigned &row, const unsigned &col);
   const T &operator()(const unsigned &row, const unsigned &col) const;

   unsigned get_rows() const;
   unsigned get_cols() const;
};

#endif