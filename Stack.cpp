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
		if (head && stack.head)
			*head = *stack.head;
		else if (!head && stack.head)
			head = new Node(*stack.head);
		else if (head && !stack.head)
		        delete head;
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
	for (int i = 0; i < 5; i++) {
		s1.add(i + 1);
	}
	Stack<int> s2;
	s2 = s1;
	Stack<char> sc1;
	for (int i = 5; i < 10; i++) {
		sc1.add(i * (i + 1));
	}
	return 0;
}

