#include "Matrix.cpp"

#include <map>

struct default_val {
    int i = -1;
};

template<typename T>
struct Csr<T> element_to_csr(struct ElementFormat<T> element) {
    struct Csr<T> csr;

    csr.N = element.NVAR;

    int elem_counter = 0;

    int m = element.NVAL / element.NELT;

    for (int i = 0; i < element.NVAL ; i++) {

        int tmp = (i % m) % (int)sqrt(m) + elem_counter;

        if (element.A_ELT[i] != 0) {
            if ( ( i + 1 ) % m == 0 && i + 1 < element.NVAL ){
                csr.VAL.push_back(element.A_ELT[i] + element.A_ELT[i+1]);
                elem_counter++;
                i++;
            }
            else {
                csr.VAL.push_back(element.A_ELT[i]);
            }
            csr.ICL.push_back(tmp);
        }
    }

    csr.NNZ = csr.VAL.size();

    int prev = -1;
    for (int i = 0 ; i < element.ELTVAR.size() ;i++) {
        if (prev != element.ELTVAR[i] ){
            csr.COLPTR.push_back(i);
            prev = element.ELTVAR[i];
        }
    }

    return csr;
}
