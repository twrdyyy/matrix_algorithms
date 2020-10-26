#include <iostream>
#include "Matrix.cpp"

/* C(i, j) = A.T(i) dot B(j)
 * 
 * C(i, j) = A(i) dot B.T(j)
 *
 */
template<typename T>
Matrix<T> mul_3a(Matrix<T> A, Matrix<T> B){

    auto m = A.get_rows();
    auto n = B.get_cols();

    auto B_T = B.transpose();

    Matrix<T> C(m, n, static_cast<T>(0));

    for(unsigned i = 0 ; i < m ; i++)
        for(unsigned j = 0 ; j < n; j++)
            C(i, j) = dot_product(A(i), B_T(j));
            
    return C;
}
