#ifndef FRACTAL_HPP
#define FRACTAL_HPP

#include <functional>
#include <complex>
#include "Matrix.hpp"

namespace fractal {
    // The type to count the number of iterations.
    using Iter_t = unsigned int;
    // The floating point type used for calculations.
    using Real = double;
    // The type for the coordinates of the complex plane.
    using Complex = std::complex<Real>;
    // The type for the object used to hold the iterative procedure to be
    // applied to every point of the coordinate matrix.
    // The iterative procedure must be a callable object with the following
    // signature:
    // - input parameter: a Complex coordinate representing the point of the
    //   complex plane for which you want to check whether it belongs to the
    //   Mandelbrot set or not;
    // - output parameter: an Iter_t which is greater than 0 if the point belongs 
    //   to the Mandelbrot set (greater values should be associated to a slower
    //   divergence speed and viceversa) and 0 otherwise.
    using Iterative_method = std::function<Iter_t(Complex)>;

    Matrix<Iter_t> apply(const Matrix<Complex> &coord,
                         const Iterative_method &f);
    // This function applies the function f to each of the complex coordinates
    // stored in matrix coord.
    // Input parameters:
    // - coord: the matrix of complex coordinates representing the area of the
    //   complex plane for which you want to draw the Mandelbrot set;
    // - f: the iterative procedure used to verify whether a point belongs to
    //   the Mandelbrot set or not.
    // Return value:
    //   a Matrix with the same dimension of the input Matrix, containing the
    //   result of the application of procedure f to each of the coordinates
    //   contained in the inout Matrix.
    
    Matrix<Complex> create_coordinates_matrix(const Complex &focus,
                                              unsigned int pixels_hor,
                                              unsigned int pixels_vert,
                                              Real width);
    // This function creates a Matrix containing the coordinates of the points
    // of the complex plane for which you want to draw the Mandelbrot set.
    // Input parameters:
    // - focus: the Complex coordinate corresponding the center of the desired
    //   image;
    // - pixels_hor: the number of pixels in the horizontal dimension;
    // - pixels_vert: the number of pixels in the vertical dimension;
    // - width: a Real number which represents the width of the image.
}

#endif
