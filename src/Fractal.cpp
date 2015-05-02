#include "Fractal.hpp"
#include <complex>

namespace fractal {
    Matrix<Iter_t> apply(const Matrix<Complex> &coord,
                         const Iterative_method &f) {  // fa una matrice di int che contiene il risultato del metodo iterativo chiamato (indicato tra gli input)
							//per ogni cella della griglia di partenza
        auto rows = coord.rows();
        auto cols = coord.cols();
        Matrix<Iter_t> m(rows, cols);
        for (unsigned int i = 1; i <= rows; ++i) {
            for (unsigned int j = 1; j <= cols; ++j) {
                m(i,j) = f(coord(i,j));
            }
        }
        return m;
    }

    Matrix<Complex> create_coordinates_matrix(const Complex &focus,
                                              unsigned int punti_hor,
                                              unsigned int punti_vert,
                                              Real width) {  //crea la griglia originaria
        Matrix<Complex> m(punti_vert, punti_hor);
        Real pixel_dimh = width/(punti_hor-1); 
        Real pixel_dimv = width/(punti_vert-1); 
        Real x = -width/2;							 		//- pixel_dimh *((punti_hor/2) + 0.5*(pixels_hor%2));
        Real y = width/2; 									//pixel_dimv * ((punti_vert/2) + 0.5*(pixels_vert%2));
        Complex aux = focus + Complex(x, y);
        for (unsigned int i = 1; i <= punti_vert; ++i) {
            for (unsigned int j = 1; j <= punti_hor; ++j) {
                m(i,j) = aux;
                aux += pixel_dimh;
            }
            y -= pixel_dimv;
            aux = Complex(x,y);
        }
        return m;
    }
}
