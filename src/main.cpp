#include "Matrix.hpp"
#include "Palette.hpp"
#include "Fractal.hpp"
#include "valuta_successione.hpp"
#include <iostream>
#include <complex>



	int main () {
		
		fractal::Complex focus(0,0);
		unsigned int punti_hor=3, punti_vert=3;
		fractal::Real width=3;
	
		Matrix<fractal::Complex> griglia = fractal::create_coordinates_matrix(focus,punti_hor,punti_vert,width);
		std::cout << griglia;		
		Matrix<fractal::Iter_t> res = 	fractal::apply( griglia, fractal::valuta_successione);
		std::cout<< res;	
			
		//Color color1(0,0,0);
		//Color color2(1,0.5,1);
		//Linear_grad lg(color1,color2);
		//Palette pal(lg, 128);
		//std::cout << "Intensita': " << pal(0.9,1) << std::endl;
		
		//fractal::create_coordinates_matrix(0,5,5,10);
	
	return 0;
	}

