#ifndef COMPLEX_NUM_HPP
    #define COMPLEX_NUM_HPP

#include <iostream>
#include <cmath>

template<class T>
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
    Complex<T> pow(const int n); //returns z^n
    T real(); //returns x if z = x + iy
    T imag(); //returns y if z = x + iy

    //OPERATORS

    void operator = (const T re); 
    void operator = (const Complex<T>& z);
    void operator += (const T re);
    void operator += (const Complex<T>& z);
    void operator -= (const T re);
    void operator -= (const Complex<T>& z);
    void operator *= (const T re);
    void operator *= (const Complex<T>& z);
    void operator /= (const T re);
    void operator /= (const Complex<T>& z);

    friend std::ostream& operator<< (std::ostream& out, const Complex<T> z);

    friend Complex<T> operator + (const Complex<T>& z1, const Complex<T>& z2);
    friend Complex<T> operator - (const Complex<T>& z1, const Complex<T>& z2);
    friend Complex<T> operator * (const Complex<T>& z1, const Complex<T>& z2);
    friend Complex<T> operator / (const Complex<T>& z1, const Complex<T>& z2);
    friend bool operator== (const Complex<T>& z1, const Complex<T>& z2);
    friend bool operator!= (const Complex<T>& z1, const Complex<T>& z2);

};

#endif