#ifndef COMPLEX_NUM_HPP
    #define COMPLEX_NUM_HPP

#include <iostream>
#include <cmath>

template<typename T>
class Complex {
private:
    T re; // Real part
    T im; // Imaginary part

public:
    //CONSTRUCTOR

    Complex(); // construction with no argument. (0+0i)
    Complex(const T re_part, const T im_part); //construction with real and imaginary part as argument
    Complex(const Complex<T>& z); //construction  with another complex number which maybe of another type (type casting will be done)
    //DECONSTRUCTOR
    ~Complex();

    //FUNCTIONS
    
    // Let z be a complex number

    Complex<T> conjugate(); //returns x - iy if z = x + iy
    double mod(); //returns square_root(x*x + y*y) if z = x + iy
    double arg(); //returns argument of complex number z. (angle made by it with real-axis on complex plane)
    Complex<T> power(const int n); //returns z^n
    T real(); //returns x if z = x + iy
    T imag(); //returns y if z = x + iy

    // //OPERATORS

    Complex<T>& operator= (const T re); 
    Complex<T>& operator= (const Complex<T>& z);
    // void operator += (const T re);
    // void operator += (const Complex<T>& z);
    // void operator -= (const T re);
    // void operator -= (const Complex<T>& z);
    // void operator *= (const T re);
    // void operator *= (const Complex<T>& z);
    // void operator /= (const T re);
    // void operator /= (const Complex<T>& z);

    friend std::ostream& operator<< (std::ostream& out, const Complex<T>& z) {
        if(z.im>=0) {
            out<<z.re<<" + "<<z.im<<"i";
        } else {
            out<<z.re<<" - "<<-z.im<<"i";
        }
        return out;
    }

    Complex<T> operator+ (const Complex<T>& z); // addition with another complex number
    Complex<T> operator+ (const T n); //addition with real number
    Complex<T> operator- (const Complex<T>& z); // subtraction with another complex number
    Complex<T> operator- (const T n); //subtraction with real number
    Complex<T> operator* (const Complex<T>& z); // multiplication with another complex number
    Complex<T> operator* (const T n); //multiplication with real number
    Complex<T> operator/ (Complex<T>& z); // division with another complex number
    Complex<T> operator/ (const T n); //division with real number
    // friend bool operator== (const Complex<T>& z1, const Complex<T>& z2);
    // friend bool operator!= (const Complex<T>& z1, const Complex<T>& z2);

};



// CONSTRUCTOR
template <typename T>
Complex<T>::Complex() {
    this->re = 0;
    this->im = 0;
}

template <typename T>
Complex<T>::Complex(const T re_part, const T im_part) {
    this->re = re_part;
    this->im = im_part;
}

template <typename T>
Complex<T>::Complex(const Complex<T>& z) {
    this->re = z.re;
    this->im = z.im;
}

// DECONSTRUCTOR
template <typename T>
Complex<T>::~Complex() {

}

// FUNCTIONS

template <typename T>
T Complex<T>::real () {
    return re;
}

template <typename T>
T Complex<T>::imag () {
    return im;
}

template <typename T>
Complex<T> Complex<T>::conjugate () {
    Complex<T> z_bar{this->re, -(this->im)};
    return z_bar;
}

template <typename T>
double Complex<T>::mod () {
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}

template <typename T>
double Complex<T>::arg () {
    double PI = 3.14159265358979323;
    if(this->re==0) {
        if(this->im==0) {
            std::cerr<<"double Complex<T>::arg() - ERROR, 0/0";
        }
        if(this->im>0) {
            return PI/2.0;
        } else {
            return -PI/2.0;
        }
    }
    double ang = atan(abs(this->im/this->re));
    if(this->im>0) {
        if(this->re>0) {
            // 1st Quadrant
            return ang;
        } else {
            // 2nd Quadrant
            return (PI-ang);
        }
    } else {
        if(this->re>0) {
            // 4th Quadrant
            return -ang;
        } else {
            // 3rd Quadrant
            return -(PI-ang);
        }
    }
}

template <typename T>
Complex<T> Complex<T>::power (const int n) {
    double r = this->mod(); //magnitude
    double a = this->arg();  // angle
    // z = x + iy can be re-written as r(e^ia) = r*cos(a)+i*r*sin(a)
    Complex<T> z1;
    z1.re = pow(r, n) * cos(a * n);
    z1.im = pow(r, n) * sin(a * n);
    return z1;
}

// OPERATORS

/* ASSIGNEMENT */
template <typename T>
Complex<T>& Complex<T>::operator= (const T re) {
    this->re = re;
    this->im = 0;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator= (const Complex<T>& z) {
    this->re = z.re;
    this->im = z.im;
    return *this;
}

/* ADDITION */
template <typename T>
Complex<T> Complex<T>::operator+ (const T n) {
    Complex<T> z_final{this->re + n, this->im};
    return z_final;
}

template <typename T>
Complex<T> Complex<T>::operator+ (const Complex<T>& z) {
    Complex<T> z_final{this->re + z.re, this->im + z.im};
    return z_final;
}

/* SUBTRACTION */
template <typename T>
Complex<T> Complex<T>::operator- (const T n) {
    Complex<T> z_final{this->re - n, this->im};
    return z_final;
}

template <typename T>
Complex<T> Complex<T>::operator- (const Complex<T>& z) {
    Complex<T> z_final{this->re - z.re, this->im - z.im};
    return z_final;
}

/* MULTIPLICATION */
template <typename T>
Complex<T> Complex<T>::operator* (const T n) {
    Complex<T> z_final{this->re * n, this->im * n};
    return z_final;
}

template <typename T>
Complex<T> Complex<T>::operator* (const Complex<T>& z) {
    Complex<T> z_final{this->re * z.re - this->im * z.im, this->re * z.im + this->im * z.re};
    return z_final;
}

/* DIVISION */
template <typename T>
Complex<T> Complex<T>::operator/ (const T n) {
    if(n==0){
        std::cerr<<"Complex<T>::operator/ - ERROR: Division by zero";
    }
    Complex<T> z_final{this->re / n, this->im / n};
    return z_final;
}

template <typename T>
Complex<T> Complex<T>::operator/ (Complex<T>& z) {
    if(z.re==0 && z.im==0) {
        std::cerr<<"Complex<T>::operator/ - ERROR: Division by zero";
    } 
    Complex<T> z_final;
    z_final = ((*this)*(z.conjugate()))/pow(z.mod(), 2);
    return z_final;
}
#endif