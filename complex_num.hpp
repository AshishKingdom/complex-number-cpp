/*
    Complex Number Library in C++
    @Author: AshishKingdom (Ashish Kushwaha)
*/

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
    /**
    * @brief construction with real and imaginary part as argument
    * @param re_part real part
    * @param im_part imaginary part
    */
    Complex(const T re_part, const T im_part);
    /**
    * @brief construction  with another complex number which maybe of another type (type casting will be done)
    * @param z complex object
    */
    Complex(const Complex<T>& z); 
    /**
    * @brief destroy the created objects (decontructor)
    */
    ~Complex();

    //FUNCTIONS

    // Let z be a complex number
    
    /**
    * @brief Used to return conjugate of the given complex number.
    * @return x - iy if z = x + iy.
    */
    Complex<T> conjugate();
    
    /**
    * @brief Used to return the square root of the given complex number.
    * @return square_root(x*x + y*y) if z = x + iy.
    */
    double mag();
    
    /**
    * @brief Used to return argument i.e angle made by complex no z on complex plane.
    * @return argument of complex number z.
    */
    double arg();
    
    /**
    * @brief Used to return z^n.
    * @param n power_number
    * @return z^n.
    */
    Complex<T> power(const int n); 
    
    /**
    * @brief Used to return real part of complex number.
    * @return x if z = x + iy.
    */
    T real(); //returns 
    
    /**
    * @brief Used to return imaginary part of complex number.
    * @return  y if z = x + iy.
    */
    T imag(); 

    // //OPERATORS

    Complex<T>& operator= (const T re);
    Complex<T>& operator= (const Complex<T>& z);
    Complex<T>& operator += (const T n);
    Complex<T>& operator += (const Complex<T>& z);
    Complex<T>& operator -= (const T n);
    Complex<T>& operator -= (const Complex<T>& z);
    Complex<T>& operator *= (const T n);
    Complex<T>& operator *= (const Complex<T>& z);
    Complex<T>& operator /= (const T n);
    Complex<T>& operator /= (Complex<T>& z);

    friend std::ostream& operator<< (std::ostream& out, const Complex<T>& z) {
        if (z.im >= 0) {
            out << z.re << " + " << z.im << "i";
        } else {
            out << z.re << " - " << -z.im << "i";
        }
        return out;
    }
    
    /**
    * @brief addition of z with another complex number.
    * @param z complex object.
    * @return addition owith another complex number.
    */
    Complex<T> operator+ (const Complex<T>& z); 
    
    /**
    * @brief addition with real number.
    * @param n real number.
    */
    Complex<T> operator+ (const T n); 
    
    /**
    * @brief subtraction with another complex number.
    * @param z complex object.
    */
    Complex<T> operator- (const Complex<T>& z); 
    
    /**
    * @brief subtraction with real number.
    * @param n real number.
    */
    Complex<T> operator- (const T n); 
    
    /**
    * @briefmultiplication with another complex number
    * @param z complex object
    */
    Complex<T> operator* (const Complex<T>& z); 
    
    /**
    * @brief multiplication with real number
    * @param n real number
    */
    Complex<T> operator* (const T n); 
    
    /**
    * @brief division with another complex number
    * @param z complex object
    */
    Complex<T> operator/ (Complex<T>& z); // 
    
    /**
    * @brief division with real number
    * @param n real number
    */
    Complex<T> operator/ (const T n); //
    
    bool operator== (const Complex<T>& z); // == operator with another complex number
    bool operator== (const T n); // == operator with real number
    bool operator!= (const Complex<T>& z); // != operator with another complex number
    bool operator!= (const T n); // != operator with real number

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
double Complex<T>::mag () {
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}

template <typename T>
double Complex<T>::arg () {
    double PI = 3.14159265358979323;
    if (this->re == 0) {
        if (this->im == 0) {
            std::cerr << "double Complex<T>::arg() - ERROR, 0/0";
        }
        if (this->im > 0) {
            return PI / 2.0;
        } else {
            return -PI / 2.0;
        }
    }
    double ang = atan(abs(this->im / this->re));
    if (this->im > 0) {
        if (this->re > 0) {
            // 1st Quadrant
            return ang;
        } else {
            // 2nd Quadrant
            return (PI - ang);
        }
    } else {
        if (this->re > 0) {
            // 4th Quadrant
            return -ang;
        } else {
            // 3rd Quadrant
            return -(PI - ang);
        }
    }
}

template <typename T>
Complex<T> Complex<T>::power (const int n) {
    double r = this->mag(); //magnitude
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
    if (n == 0) {
        std::cerr << "Complex<T>::operator/ - ERROR: Division by zero";
    }
    Complex<T> z_final{this->re / n, this->im / n};
    return z_final;
}

template <typename T>
Complex<T> Complex<T>::operator/ (Complex<T>& z) {
    if (z.re == 0 && z.im == 0) {
        std::cerr << "Complex<T>::operator/ - ERROR: Division by zero";
    }
    Complex<T> z_final;
    z_final = ((*this) * (z.conjugate())) / pow(z.mag(), 2);
    return z_final;
}

/* == OPERATOR */
template <typename T>
bool Complex<T>::operator== (const T n) {
    return ((this->re == n) && (this->im == 0));
}

template <typename T>
bool Complex<T>::operator== (const Complex<T>& z) {
    return ((this->re == z.re) && (this->im == z.im));
}

/* != OPERATOR */
template <typename T>
bool Complex<T>::operator!= (const T n) {
    return !((*this) == n);
}

template <typename T>
bool Complex<T>::operator!= (const Complex<T>& z) {
    return !((*this) == z);
}

/* += OPERATOR */
template <typename T>
Complex<T>& Complex<T>::operator+= (const T n) {
    this->re += n;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator+= (const Complex<T>& z) {
    this->re += z.re;
    this->im += z.im;
    return *this;
}

/* -= OPERATOR */
template <typename T>
Complex<T>& Complex<T>::operator-= (const T n) {
    this->re -= n;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator-= (const Complex<T>& z) {
    this->re -= z.re;
    this->im -= z.im;
    return *this;
}

/* *= OPERATOR */
template <typename T>
Complex<T>& Complex<T>::operator*= (const T n) {
    this->re *= n;
    this->im *= n;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator*= (const Complex<T>& z) {
    T re_part, im_part;
    re_part = this->re * z.re - this->im * z.im;
    im_part = this->re * z.im + this->im * z.re;
    this->re = re_part;
    this->im = im_part;
    return *this;
}

/* /= OPERATOR */
template <typename T>
Complex<T>& Complex<T>::operator/= (const T n) {
    this->re /= n;
    this->im /= n;
    return *this;
}

template <typename T>
Complex<T>& Complex<T>::operator/= (Complex<T>& z) {
    double mag = pow(z.mag(), 2);
    T re_part, im_part;
    re_part = (this->re * z.re + this->im * z.im) / mag;
    im_part = (this->im * z.re - this->re * z.im) / mag;
    this->re = re_part;
    this->im = im_part;
    return *this;
}
#endif
