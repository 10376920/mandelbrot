#ifndef MATRIX_HPP  // header guard: se ha già letto hpp non lo rileggere!
#define MATRIX_HPP

#include <vector>
#include <iostream>

//MEMENTO ALL'USO DELLA CLASSE MATRICE:
// PER CREARE UNA MATRICE: usare Matrix<chetipodiariabilecivogliomettere>  matrice (numeri righe, numero colonne)
// PER MODIFICARNE I VALORI AL SUO INTERNO : usare le parentesi tonde

// definiamo la classe template Matrix
template <typename T> 
class Matrix {
    private:
    std::vector <T> _v; //ha un campo vettore
    unsigned int _n,_m; //due insigned int per numero righe e numero colonne
    
    public:
    Matrix ( unsigned int n, unsigned int m ); //constructor
    T & operator() (unsigned int r, unsigned int c); //per estrearre gli elementi della matrice
    const T & operator() (unsigned int r, unsigned int c) const; //per estrearre gli elementi della matrice versione const
    unsigned int rows () const; // restituisce il numero di righe della matrice
    unsigned int cols () const; // restituisce il numero di colonne 
};

template<typename T>
Matrix<T>::Matrix ( unsigned int n, unsigned int m ) : _n(n),_m(m) { //CONSTRUCTOR: riserva lo spazio per la matrice, vetore di m*n elementi
    _v.reserve(n*m);
}

template<typename T>
T & Matrix<T>::operator() (unsigned int r,unsigned int c){ //restituisce una reference all'elemento di riga r e colonna c
	return _v[_m*(r-1)+(c-1)]; //N.B. : convenzione: iniziamo a contare da 1 e non da 0.
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


//funzione per stampare le matrici intere a video: fa overloading dell'operator <<
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

#endif
