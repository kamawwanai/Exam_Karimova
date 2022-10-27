#include "factorial.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

std::uint64_t Task1::factorial(std::uint64_t number) {
	if (number < 0)
		throw std::invalid_argument("The argument cannot be negative!");
	if (number == 0)
		return 1;
	return (number * Task1::factorial(number - 1));
}