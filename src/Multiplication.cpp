#include <iostream>
#include <chrono>
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

void matrix_mul(){ 
    Matrix<float> A(1000, 1000, 1.12);
    Matrix<float> B(1000, 1000, 1.77);
    auto start = std::chrono::high_resolution_clock::now();
    Matrix<float> C = mul_3a(A, B); 
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << elapsed.count() << std::endl;
}
