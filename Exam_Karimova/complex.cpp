#include <iostream>
#include <exception>
#include <stdexcept>
#include "complex.hpp"

Task2::Complex Task2::Complex::operator+(Task2::Complex& b) {
	long double b_real = b.getReal();
	long double b_image = b.getImage();
	Task2::Complex tmp(_real + b_real, _image + b_image);
	return tmp;
}

Task2::Complex Task2::Complex::operator-(Task2::Complex& b) {
	long double b_real = b.getReal();
	long double b_image = b.getImage();
	Task2::Complex tmp(_real - b_real, _image - b_image);
	return tmp;
}

Task2::Complex Task2::Complex::operator*(Task2::Complex& b) {
	long double b_real = b.getReal();
	long double b_image = b.getImage();
	Task2::Complex tmp(_real*b_real-_image*b_image, _real*b_image+_image*b_real);
	return tmp;
}

Task2::Complex Task2::Complex::operator/(Task2::Complex& b) {
	if (b.getImage() == 0 && b.getReal() == 0) {
		throw std::invalid_argument("The divisor cannot be zero");
	}
	long double b_real = b.getReal();
	long double b_image = b.getImage();
	long double to_divide = b_real * b_real + b_image * b_image;
	Task2::Complex tmp((_real*b_real+_image*b_image)/to_divide,
		(_image*b_real-_real*b_image)/to_divide);
	return tmp;
}

std::ostream& operator<<(std::ostream& out, Task2::Complex& a) {
	if (a.getImage() < 0)
		out << a.getReal() << " - " << abs(a.getImage()) << "i";
	else 
		out << a.getReal() << " + " << a.getImage() << "i";
	return out;
}

std::istream& operator>>(std::istream& in, Task2::Complex& a) {
	long double real;
	long double image;
	in >> real >> image;
	a.setReal(real);
	a.setImage(image);
	return in;
}
