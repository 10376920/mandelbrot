#include "Matrix.hpp"
#include <iostream>
#include <complex>

using complex= std::complex<double>;

int main () {

	Matrix<int> mat(2,2);
	mat(1,1)=1;
	mat(1,2)=2;
	mat(2,1)=3;
	mat(2,2)=4;
	
	std::cout << mat;
		
	Matrix<complex> mat1(2,2);
	mat1(1,1)=complex(1,1);
	mat1(1,2)=complex(1,2);
	mat1(2,1)=complex(1,3);
	mat1(2,2)=complex(1,4);
	
	std::cout << mat1;
	
	
	return 0;
}
