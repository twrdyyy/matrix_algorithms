#include <iostream>
#include <chrono>
#include <iterator>

#include "Gauss.cpp"

int main() {

    std::string file_path = "res/mat.txt";

    Matrix<float> A = load_matrix_from_file<float>(file_path);
    A.print();
    std::cout << "Gauss elimination with partial pivoting:" << std::endl;
    A = gauss_collumn_pivot(A);
    A.print();

    return 0;
}
