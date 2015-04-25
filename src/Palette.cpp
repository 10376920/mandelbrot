#include "Palette.hpp"

Palette::Palette(const std::function<Color(double)> &f,
                 unsigned int n_colors,
                 double min,
                 double max):
      _n_colors(n_colors), _min(min), _max(max), _f(f){
    assert(_min >= 0.0 && _max <= 1.0);
    make_palette();
}

void Palette::set_n_colors(unsigned int n) {
    _n_colors = n;
    make_palette();
}

double Palette::operator()(double val, unsigned int i) const {
    assert(val >= 0.0 && val <= 1.0 && i < 3);
    return _v[val*(_n_colors-1)].get(i);
}

Color Palette::operator()(double val) const {
    assert(val >= 0.0 && val <= 1.0);
    return _v[val*_n_colors];
}

void Palette::make_palette() {
    _v.resize(_n_colors);
    for (unsigned int i = 0; i<_n_colors; ++i) {
        _v[i] = _f(double(i)/(_n_colors-1));
    }
}
