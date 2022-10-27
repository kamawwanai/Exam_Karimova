#pragma once
#include <iostream>

namespace Task2 {
	
	struct Complex {
	private:
		long double _real, _image;
	public:
		Complex(long double real, long double image) :
			_real(real), _image(image) {}

		Complex() : _real(0), _image(0) {}
		
		long double getReal() { return _real; }

		long double getImage() { return _image; }

		void setReal(long double real) { _real = real; }

		void setImage(long double image) { _image = image; }


		Complex operator+(Complex& b);
		
		Complex operator-(Complex& b);
	
		Complex operator*(Complex& b);

		Complex operator/(Complex& b);
	};
}

std::ostream& operator<<(std::ostream& out,  Task2::Complex& a);

std::istream& operator>>(std::istream& in, Task2::Complex& a);
