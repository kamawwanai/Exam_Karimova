#include "linked_list.hpp"
#include <cinttypes>
#include <exception>
#include <stdexcept>
#include <iostream>


Task4::LinkedList::LinkedList(std::uint32_t size, NODE_VALUE_TYPE default_value)
	: _size(size)
{
	head = new ListNode(default_value);
	ListNode* iter = head;
	for (std::uint32_t i = 1; i < size; ++i) {
		iter->next = new ListNode(default_value);
		iter = iter->next;
	}
}

Task4::LinkedList::ListNode& Task4::LinkedList::operator[](std::uint32_t index) {
	if (index >= _size)
		throw std::invalid_argument("Index out of range");

	std::uint32_t i = 0;
	ListNode* iter = head;
	while (i != index) {
		iter = iter->next;
		i++;
	}
	return *iter;
}

Task4::LinkedList::~LinkedList() {
	ListNode* iter = head;
	ListNode* next = head->next;
	while (iter != nullptr || iter == head) {
		delete iter;
		iter = next;
		if (iter != nullptr)
			next = iter->next;
	}
	head = nullptr;
}

void Task4::LinkedList::push_back(NODE_VALUE_TYPE value) {
	auto iter = head;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	_size++;
	iter->next = new ListNode(value);
}

//std::ostream& operator<<(std::ostream& out, Task4::NODE_VALUE_TYPE a) {
//	out << (int)a;
//	return out;
//}
//
//std::istream& operator>>(std::istream& in, Task4::NODE_VALUE_TYPE a) {
//	in >> (int)a;
//	return in;
//}


std::ostream& operator<<(std::ostream& out, Task4::LinkedList& list) {
	for (std::uint32_t i = 0; i < list.getSize(); ++i) {
		out << list[i].value << ' ';
	}
	return out;
}

std::istream& operator>>(std::istream& in, Task4::LinkedList& list) {
	for (std::uint32_t i = 0; i < list.getSize(); i++) {
		in >> list[i].value;
	}
	return in;
}