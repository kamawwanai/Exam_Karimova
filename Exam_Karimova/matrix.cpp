#include "matrix.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cinttypes>

Task3::Matrix Task3::operator*(Task3::Matrix& a, Task3::Matrix& b) {
	if (a.getWidth() != b.getHeight()) {
		throw std::invalid_argument("Cannot multiply with different width of first and height of second");
	}
	Task3::Matrix c(a.getHeight(), b.getWidth());
	for (std::uint32_t i = 0; i < c.getHeight(); i++) {
		for (std::uint32_t j = 0; j < c.getWidth(); j++) {
			for (std::uint32_t p = 0; p < a.getWidth(); p++) {
				c[i][j] += a[i][p] * b[p][j];
			}
		}
	}
	return c;
}

std::istream& operator>>(std::istream& in, Task3::Matrix& a) {
	for (std::uint32_t i = 0; i < a.getHeight(); ++i) {
		for (std::uint32_t j = 0; j < a.getWidth(); ++j) {
			in >> a[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, Task3::Matrix& a) {
	for (std::uint32_t i = 0; i < a.getHeight(); i++) {
		for (std::uint32_t j = 0; j < a.getWidth(); j++) {
			out << a[i][j] << ' ';
		}
		out << std::endl;
	}
	return out;
}