#include <iostream>
#include <iterator>

#include "Compression.cpp"

int main() {
    struct ElementFormat<int> element;
    element.NELT = 2;
    element.NVAR = 3;
    element.NVAL = 8;
    element.ELTVAR = {0,1,1,2};
    element.ELTPTR = {0, 5};
    element.A_ELT = {1,0,0,1,1,3,5,0};

    auto a = element_to_csr(element);
    return 0;
}

/* #include "Gauss.cpp" */

/* int main() { */

/*     std::string file_path = "res/mat.txt"; */

/*     Matrix<float> A = load_matrix_from_file<float>(file_path); */
/*     A.print(); */
/*     std::cout << "Gauss elimination with partial pivoting:" << std::endl; */
/*     A = gauss_collumn_pivot(A); */
/*     A.print(); */

/*     return 0; */
/* } */

