#include <complex>
#include "Matrix.hpp"
#include "Fractal.hpp"
#include "valuta_successione.hpp"

namespace fractal {

	Iter_t valuta_successione(Complex num){
	
		// se ha modulo maggiore di due diverge, non appartiene all'insieme, è interessante e mi salvo quanto ci ho messo ad arrivare lì
		//se alla fine ha modulo minore di due converge quidi non è un punto interessante
		
		int N=100; // numero massimo iterazioni
		Iter_t res; //risultato
		Complex z(0,0);	
			
			for (int it=0; it < N; ++it){
				if (std::norm(z) > 2 ) { //quando scopri che diverge (mod > 2) salva quanto tempo ci ha messo a divergere
					res=it;
				}
					
				z=z*z+num;
			}
			if (std::norm(z)<2)
				res=0; //se converge salvo arbitrariamente 0 come valore.
		return res;
	}
	
}
