#include "stdafx.h"
#include "iostream"

using namespace std;

class Tree {
	struct Node{
		int value;
		Node *left;
		Node *right;
		Node(int num) {
			value = num;
			left = nullptr;
			right = nullptr;
		}
		Node(const Node &node) {
			value = node.value;
			left = node.left ? new Node(*node.left) : nullptr;
			right = node.right ? new Node(*node.right) : nullptr;
		}
		~Node() {
			if (left)
				delete left;
			if (right)
				delete right;
		}
		Node& operator=(const Node &node) {
			value = node.value;
			if (left)
				delete left;
			if (right)
				delete right;
			left = node.left ? new Node(*node.left) : nullptr;
			right = node.right ? new Node(*node.right) : nullptr;
			return *this;
		}
	}; //struct Node

	Node *root;
public:
	Tree(int num) {
		root = new Node(num);
	}
	Tree(const Tree &tree) {
		root = new Node(*tree.root);
	}
	~Tree() {
		if (root)
			delete root;
	}
	Tree& operator=(const Tree &tree) {
		*root = *tree.root;
		return *this;
	}

	bool add(int num) {
		Node *found = root;
		Node *vp = root;
		while (vp) {
			found = vp;
			if (found->value == num) {
				vp = nullptr;
				return false;
			}
			else {
				vp = found->value > num ? found->left : found->right;
			}
		} //while
		if (found->value > num) {
			found->left = new Node(num);
			return true;
		}
		else {
			found->right = new Node(num);
			return true;
		}
	} //add
};

int _tmain(int argc, _TCHAR* argv[]){
	Tree tr1(5);
	tr1.add(3);
	tr1.add(7);
	tr1.add(2);
	tr1.add(8);
	tr1.add(6);
	tr1.add(2);

	Tree tr2 = tr1;
	tr2.add(10);
	tr2.add(1);
	
	Tree tr3(51);
	tr1 = tr3;
	
	return 0;
}
