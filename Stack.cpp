#include "stdafx.h"
#include "iostream"

using namespace std;

template<class Type> class Stack {
	struct Node {
		Type value;
		Node *next;
		Node() {
			next = nullptr;
		}
		Node(Type arg) {
			value = arg;
			next = nullptr;
		}
		Node(const Node &node) {
			value = node.value;
			next = node.next ? new Node(*node.next) : nullptr;
		}
		~Node() {
			if (next)
				delete next;
		}
		Node& operator=(const Node &node) {
			value = node.value;
			if (next)
				delete next;
			next = node.next ? new Node(*node.next) : nullptr;
			return *this;
		}
	}; //struct Node
	Node *head;
public:
	Stack() {
		head = nullptr;
	}
	Stack(const Stack &stack) {
		head = new Node(*stack.head);
	}
	~Stack() {
		if (head)
			delete head;
	}
	Stack& operator=(const Stack &stack) {
		if (head)
			*head = *stack.head;
		else
			head = new Node(*stack.head);
		return *this;
	}
	void add(Type arg) {
		Node *newNode = new Node(arg);
		newNode->next = head;
		head = newNode;
	}
};

int _tmain(int argc, _TCHAR* argv[]) {
	Stack<int> s1;
	for (int i = 25; i < 31; i++) {
		s1.add(i);
	}
	Stack<int> s2;
	s2 = s1;
	Stack<char> sc1;
	for (int i = 5; i < 10; i++) {
		sc1.add(i * i);
	}
	return 0;
}

