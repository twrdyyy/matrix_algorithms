#include <iostream>

#include "Matrix.cpp"

int main() {
  Matrix<float> mat1(10, 10, 1.0);
  Matrix<float> mat2(10, 10, 2.0);
  Matrix<float> mat3 = mat2 + mat1;
  return 0;
}
