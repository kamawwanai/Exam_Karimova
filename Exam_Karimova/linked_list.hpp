#pragma once
#include <cinttypes>
#include <exception>
#include <stdexcept>

namespace Task4 {

	using NODE_VALUE_TYPE = int;
	struct LinkedList {
	public:

		struct ListNode {
			NODE_VALUE_TYPE value;
			ListNode* next = nullptr;

			ListNode() { value = 0; }

			ListNode(NODE_VALUE_TYPE _value) : value(_value) { }

			ListNode(NODE_VALUE_TYPE _value, ListNode* _next) : value(_value), next(_next) {}

		};

		LinkedList(std::uint32_t size, NODE_VALUE_TYPE default_value);

		LinkedList(std::uint32_t size) : LinkedList(size, 0) {}

		ListNode& operator[](std::uint32_t index);

		~LinkedList();

		void push_back(NODE_VALUE_TYPE value);

		std::uint32_t getSize() {
			return _size;
		}

	private:

		ListNode* head;

		std::uint32_t _size;

	};
}

//std::ostream& operator<<(std::ostream& out, Task4::NODE_VALUE_TYPE a);
//
//std::istream& operator>>(std::istream& in, Task4::NODE_VALUE_TYPE a);


std::ostream& operator<<(std::ostream& out, Task4::LinkedList& list);

std::istream& operator>>(std::istream& in, Task4::LinkedList& list);