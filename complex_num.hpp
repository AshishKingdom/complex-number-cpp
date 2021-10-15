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
    // Complex(const Complex<T>& z); //construction  with another complex number which maybe of another type (type casting will be done)

    //DECONSTRUCTOR
    ~Complex();

    //FUNCTIONS
    
    // Let z be a complex number

    // Complex<T> conjugate(); //returns x - iy if z = x + iy
    // double mod(); //returns square_root(x*x + y*y) if z = x + iy
    // double arg(); //returns argument of complex number z. (angle made by it with real-axis on complex plane)
    // Complex<T> pow(const int n); //returns z^n
    // T real(); //returns x if z = x + iy
    // T imag(); //returns y if z = x + iy

    // //OPERATORS

    // void operator = (const T re); 
    // void operator = (const Complex<T>& z);
    // void operator += (const T re);
    // void operator += (const Complex<T>& z);
    // void operator -= (const T re);
    // void operator -= (const Complex<T>& z);
    // void operator *= (const T re);
    // void operator *= (const Complex<T>& z);
    // void operator /= (const T re);
    // void operator /= (const Complex<T>& z);

    // template<typename D>
    // friend std::ostream& operator<< (std::ostream& out, const Complex<D> z);

    // friend Complex<T> operator + (const Complex<T>& z1, const Complex<T>& z2);
    // friend Complex<T> operator - (const Complex<T>& z1, const Complex<T>& z2);
    // friend Complex<T> operator * (const Complex<T>& z1, const Complex<T>& z2);
    // friend Complex<T> operator / (const Complex<T>& z1, const Complex<T>& z2);
    // friend bool operator== (const Complex<T>& z1, const Complex<T>& z2);
    // friend bool operator!= (const Complex<T>& z1, const Complex<T>& z2);

};



// CONSTRUCTOR
template <typename T>
Complex<T>::Complex() {
    re = 0;
    im = 0;
}

template <typename T>
Complex<T>::Complex(const T re_part, const T im_part) {
    re = re_part;
    im = im_part;
}

//DECONSTRUCTOR
template <typename T>
Complex<T>::~Complex() {

}



#endif