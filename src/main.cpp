#include <iostream>

#include "Multiplication.cpp"

int main() {
    Matrix<float> A(2, 3, 1.0);
    Matrix<float> B(3, 4, 2.0);
    Matrix<float> C = mul_3a(A, B); 
    std::cout << "A" << std::endl;
    A.print();
    std::cout << "B" << std::endl;
    B.print();
    std::cout << "C" << std::endl;
    C.print();
    return 0;
}
