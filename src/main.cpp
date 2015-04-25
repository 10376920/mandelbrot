#include "Matrix.hpp"
#include "Palette.hpp"
#include "Fractal.hpp"
#include <iostream>
#include <complex>

using complex= std::complex<double>;

int main () {
	
	double n=100,m=100;
	double x0=-1 , x=-1, y=1;
	double h=(y-x)/(n-1), k=(y-x)/(m-1);  //considero la griglia quadrata o non me la cavo più
	
	// definisco la matrice in cui inserire i numeri complessi
	Matrix<complex> mat(n,m);

	//nella matrice voglio inserire i numeri complessi compresi in una porzione di piano di Gauss tra -1 e 1 e -i e i,
	// mantenendo l'ordine della griglia
	for (int i=1; i<=n; i++){
		x=x0;
		for (int j=1; j<=m; j++) {
			mat(i,j)=complex(x,y);
			x=x+h;
		}
		y=y-k;
	}
		
	std::cout << mat;
	
	//su ogni punto della matrice valuto la sottosuccessione per N iterazioni
	// se ha modulo maggiore di due diverge, non appartiene all'insieme, è interessante e mi salvo quanto ci ho messo ad arrivare lì
	//se alla fine ha modulo minore di due converge quidi non è un punto interessante
	
	int N=100;
	Matrix<int> Iteraz(n,m);
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++) {
			complex z(0,0);	
			
			for (int it=0; it < N; ++it){
				if (std::norm(z) > 2 ) {
					Iteraz(i,j)=it;
					break; //se è maggiore di due bona, diverge, salva e esci dal ciclo
					}
					
				z=z*z+mat(i,j);
			}
			if (std::norm(z)<2)
				Iteraz(i,j)=0; //se converge salvo arbitrariamente 0 come valore.
		}
	}
	
	std::cout << Iteraz;
	
	Color color1(0,0,0);
	Color color2(1,0.5,1);
	Linear_grad lg(color1,color2);
	Palette pal(lg, 128);
	std::cout << "Intensita': " << pal(0.9,1) << std::endl;
	
	fractal::create_coordinates_matrix(0,5,5,10);
	
return 0;
}
