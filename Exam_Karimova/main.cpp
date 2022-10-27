#include "factorial.hpp"
#include "complex.hpp"
#include "matrix.hpp"
#include "linked_list.hpp"
#include <iostream>

int main() {

	// Task 1
	std::cout << "Task 1" << std:: endl;
	std::cout << "Enter a number" << std::endl;
	std::int64_t number;
	std::cin >> number;
	std::cout << "Result\n" << Task1::factorial(number) << std::endl;

	// Task 2
	std::cout << "Task 2" << std::endl;
	Task2::Complex a;
	Task2::Complex b;
	std::cout << "Enter the first complex number <example: 1 2>:" << std::endl;
	std::cin >> a;
	std::cout << "Enter the second complex number <example: 1 2>:" << std::endl;
	std::cin >> b;
	std::cout << "Values\n" << "a = " << a << "\nb = " << b << std::endl;
	Task2::Complex c = a + b;
	std::cout << "Result of sum\n" << c << std::endl;
	Task2::Complex d = a - b;
	std::cout << "Result of deduction\n" << d << std::endl;
	Task2::Complex e = a * b;
	std::cout << "Result of multiply\n" << e << std::endl;
	Task2::Complex f = a / b;
	std::cout << "Result of division\n" << f << std::endl;

	// Task 3
	std::cout << "Task 3" << std:: endl;
	std::cout << "Enter a height and a width of matrix A" << std::endl;
	std::uint32_t a_height, a_width;
	std::cin >> a_height >> a_width;
	Task3::Matrix a_matrix(a_height, a_width);
	std::cout << "Enter a matrix A" << std::endl;
	std::cin >> a_matrix;
	std::cout << "Enter a height and a width of matrix B" << std::endl;
	std::uint32_t b_height, b_width;
	std::cin >> b_height >> b_width;
	Task3::Matrix b_matrix(b_height, b_width);
	std::cout << "Enter a matrix B" << std::endl;
	std::cin >> b_matrix;
	Task3::Matrix c_matrix = a_matrix * b_matrix;
	std::cout << "Result\n" << c_matrix;

	// Task 4
	std::cout << "Enter list size:" << std::endl;
	int list_size = 0; 
	std::cin >> list_size;
	Task4::LinkedList list(list_size);

	std::cout << "Enter list values:" << std::endl;
	std::cin >> list;
	std::cout << "Enter value to push back" << std::endl;
	Task4::NODE_VALUE_TYPE q = 0;
	std::cin >> q;
	list.push_back(q);
	std::cout << "List after push back" << std::endl;
	std::cout << list << std::endl;

	return 0;
}