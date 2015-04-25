#ifndef PALETTE_HPP
#define PALETTE_HPP

#include <functional>
#include <vector>
#include <cassert>

class Color {
  private:
    std::array<double, 3> _val;
  public:
    Color(): _val{0.0, 0.0, 0.0} {};
    Color(double red, double green, double blue): _val{red, green, blue} {}
    void set_red(double red) {_val[2] = red;}
    void set_green(double green) {_val[1] = green;}
    void set_blue(double blue) {_val[0] = blue;}
    void set(double val,unsigned int index) {_val[index] = val;}
    void set(double red, double green, double blue) {
        _val[2] = red;
        _val[1] = green;
        _val[0] = blue;
    }
    double get_red() const {return _val[2];};
    double get_green() const {return _val[1];}
    double get_blue() const {return _val[0];}
    double get(unsigned int index) const {return _val[index];}
    void get(double &red, double &green, double &blue) {
        red = _val[2];
        green = _val[1];
        blue = _val[0];
    }
};

class Palette {
  private:
    unsigned int _n_colors;
    double _min;
    double _max;
    std::vector<Color> _v;
    std::function<Color(double)> _f;
    void make_palette();
  public:
    Palette(const std::function<Color(double)> &f, unsigned int n_colors,
            double min = 0.0, double max = 1.0);
    void set_min(double min) {_min = min;}
    void set_max(double max) {_max = max;}
    void set_n_colors(unsigned int n);
    double operator()(double val, unsigned int i) const;
    Color operator()(double val) const;
};

class Linear_grad {
  private:
    Color _a;
    Color _b;
    double _diff_red;
    double _diff_green;
    double _diff_blue;
  public:
    Linear_grad(): _a(), _b() {}
    Linear_grad(Color a, Color b): _a(a), _b(b) {
        _diff_red = _b.get_red() - _a.get_red();
        _diff_green = _b.get_green() - _a.get_green();
        _diff_blue = _b.get_blue() - _a.get_blue();
    }
    Color operator()(double val) const {
        return Color(_a.get_blue() + _diff_blue*val,
              _a.get_green() + _diff_green*val,
              _a.get_red() + _diff_red*val);
    }
};

#endif
