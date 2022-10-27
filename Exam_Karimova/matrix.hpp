#pragma once
#include <cinttypes>
#include <vector>
#include <iostream>

namespace Task3 {

	class Matrix {
	private:
		std::uint32_t _height, _width;
		std::vector< std::vector<long double> > _matrix;
	public:
		Matrix(std::uint32_t height, std::uint32_t width) :
			_height(height),
			_width(width),
			_matrix(std::vector< std::vector<long double>>(height, std::vector<long double>(width, 0)))
		{}

		std::vector<long double>& operator[](uint32_t index) {
			return _matrix[index];
		}

		std::uint32_t getHeight() { return _height; }

		std::uint32_t getWidth() { return _width; }
	};

	Matrix operator*(Matrix& a, Matrix& b);
}

std::istream& operator>>(std::istream& in, Task3::Matrix& a);

std::ostream& operator<<(std::ostream& out, Task3::Matrix& a);