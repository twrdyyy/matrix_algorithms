#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

template<typename T>
struct ElementFormat {
    int NELT;
    int NVAR;
    int NVAL;
    std::vector<T> ELTVAR;
    std::vector<T> ELTPTR;
    std::vector<T> A_ELT;
};

template<typename T>
struct Csr {
    int NNZ;
    int N;
    std::vector<T> ICL;
    std::vector<T> VAL;
    std::vector<T> COLPTR;
};

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

   std::vector<T> &operator()(const unsigned &row);

   T &operator()(const unsigned &row, const unsigned &col);
   const T &operator()(const unsigned &row, const unsigned &col) const;

   unsigned get_rows() const;
   unsigned get_cols() const;

   void print();
};

template <typename T>
Matrix<T> load_matrix_from_file(const std::string&);

#endif
