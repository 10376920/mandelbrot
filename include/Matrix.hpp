#include <vector>
#include <iostream>

template <typename T> 
class Matrix {
    private:
    std::vector <T> _v;
    unsigned int _n,_m;
    
    public:
    Matrix ( unsigned int n, unsigned int m );
    T & operator() (unsigned int r, unsigned int c);
    const T & operator() (unsigned int r, unsigned int c) const;
    unsigned int rows () const;
    unsigned int cols () const;
};

template<typename T>
Matrix<T>::Matrix ( unsigned int n, unsigned int m ) : _n(n),_m(m) {
    _v.reserve(n*m);
}

template<typename T>
T & Matrix<T>::operator() (unsigned int r,unsigned int c){
	return _v[_m*(r-1)+(c-1)];
}

template<typename T>
const T & Matrix<T>::operator() (unsigned int r,unsigned int c) const{
	return _v[_m*(r-1)+(c-1)];
}

template<typename T>
unsigned int Matrix<T>::rows () const {
	return _n;
}

template<typename T>
unsigned int Matrix<T>::cols () const {
	return _m;
}


template<typename T>
std::ostream & operator<< (std::ostream & os, const Matrix<T> & mat ){

	for ( unsigned int j=1; j <= mat.rows() ; j++) {
		for ( unsigned int i=1; i <= mat.cols() ; i++) {
			os << mat (j,i) << " ";
		}
		os << std::endl;
	}

	return os;
}
