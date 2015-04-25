#include "Fractal.hpp"
#include <complex>

namespace fractal {
    Matrix<Iter_t> apply(const Matrix<Complex> &coord,
                         const Iterative_method &f) {
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
                                              unsigned int pixels_hor,
                                              unsigned int pixels_vert,
                                              Real width) {
        Matrix<Complex> m(pixels_hor, pixels_vert);
        Real pixel_dim = width/pixels_hor;
        Real x = - pixel_dim *
                   ((pixels_hor/2) + 0.5*(pixels_hor%2));
        Real y = - pixel_dim *
                   ((pixels_vert/2) + 0.5*(pixels_vert%2));
        Complex aux = focus + Complex(x, y);
        for (unsigned int i = 1; i <= pixels_vert; ++i) {
            for (unsigned int j = 1; j <= pixels_hor; ++j) {
                m(i,j) = aux;
                aux += pixel_dim;
            }
            y += pixel_dim;
            aux = Complex(x,y);
        }
        return m;
    }
}
