#include <vector>

class Matrix {
    private:
    std::vector <int> _v;
    unsigned int _n,_m;
    
    public:
    Matrix ( unsigned int n, unsigned int m );
    
};

Matrix::Matrix ( unsigned int n, unsigned int m ) : _n(n),_m(m) {
    _v.reserve(n*m);
}
