# complex-number-cpp
A C++ library which allow you to use complex number in your program

# How to use?
Below is a simple to program which show use of all functions available in this library

```cpp
// include Complex number library
#include "complex_num.hpp"

#include <iostream>

int main() {
	// Create of 2 complex numbers of type double
	Complex<double> z1(3, 4);
	Complex<double> z2(-2, 5);

	// print complex numbers
	std::cout << "z1 = " << z1 << " and z2 = " << z2 << '\n';
	// print conjugate of complex numbers
	std::cout << "Conjugate of z1 = " << z1.conjugate() << " and conjugate of z2 = " << z2.conjugate() << '\n';
	// print magnitude of complex numbers
	std::cout << "Magnitude of z1 = " << z1.mag() << " and magnitude of z2 = " << z2.mag() << '\n';
	// print complex number raised to any integeral power
	std::cout << "z1 raised to power 2 = " << z1.power(2) << " and z2 raised to power -1 = " << z2.power(-1) << '\n';
	// print argument of complex numbers
	std::cout << "Argument of z1 = " << z1.arg() << " and argument of z2 = " << z2.arg() << '\n';
	// print real part of complex numbers
	std::cout << "Real part of z1 = " << z1.real() << " and real part of z2 = " << z2.real() << '\n';
	// print imaginary part of complex numbers
	std::cout << "Imaginary part of z1 = " << z1.imag() << " and imaginary part of z2 = " << z2.imag() << '\n';
	// addition of a complex number with another complex number
	std::cout << "z1 + z2 = " << (z1 + z2) << '\n';
	// subtraction of a complex number with another complex number
	std::cout << "z1 - z2 = " << (z1 - z2) << '\n';
	// multiplication of a complex number with another complex number
	std::cout << "z1 * z2 = " << (z1 * z2) << '\n';
	// division of a complex number with another complex number
	std::cout << "z1 / z2 = " << (z1 / z2) << '\n';
	// addition of a complex number with real number
	std::cout << "z1 + 10 = " << (z1 + 10) << '\n';
	// subtraction of a complex number with another real number.
	std::cout << "z1 - 10 = " << (z1 - 10) << '\n';
	// multiplication of a complex number with another real number.
	std::cout << "z1 * 10 = " << (z1 * 10) << '\n';
	// division of a complex number with another real number.
	std::cout << "z1 / 10 = " << (z1 / 10) << '\n';
	// NOTE: +=, -=, *= and /= operators are also supported

	// checking equality with == operator
	if (z1 == z2) {
		std::cout << "z1 and z2 are equal \n";
	} else {
		std::cout << "z1 and z2 are not equal \n";
	}
	// NOTE: != operator is also supported

	return 0;
}
```
