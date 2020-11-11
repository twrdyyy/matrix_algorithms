#include "Matrix.cpp"

template<typename T>
void swap_cols(Matrix<T> &A, unsigned i, unsigned j) {
    for(unsigned x = 0; x < A.get_rows(); x++)
        std::swap(A(x,i), A(x,j));
}

template<typename T>
Matrix<T> gauss_collumn_pivot(Matrix<T> A) {

    auto n = A.get_rows();
    //auto m = A.get_cols();

    unsigned max_idx;

    for(unsigned k = 0; k < n; k++){

        max_idx = k;
        for ( unsigned i = k+1; i < n; i++) {
            max_idx = (A(k, max_idx) < A(k, i) ? i : max_idx);
        }

        if (max_idx != k)
            swap_cols(A, max_idx, k);

        auto Akk = A(k, k);
        for(unsigned i = k ; i < n; i++) A(i, k) /= Akk;

        for(unsigned j = k+1; j < n; j++){
            for(unsigned i = k; i < n; i++){
                A(i, j) -= A(i,k)*A(k, j); 
            }
        }
    }

    return A;
}
