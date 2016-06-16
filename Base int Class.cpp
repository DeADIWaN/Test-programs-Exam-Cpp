#include "stdafx.h"
#include "iostream"

using namespace std;
class Ukaz{
	int *a, *b;
public:
	Ukaz() {
		a = nullptr;
		b = nullptr;
	}
	Ukaz(int c, int d) {
		a = new int(c);
		b = new int(d);
	}
	Ukaz(const Ukaz &obj) {
		if (obj.a != nullptr) {
			a = new int(*obj.a);
		}
		else {
			a = nullptr;
		};
		if (obj.b != nullptr) {
			b = new int(*obj.b);
		}
		else {
			b = nullptr;
		};
	}
	~Ukaz() {
		if (a != nullptr) {
			delete a;
		};
		if (b != nullptr) {
			delete b;
		};
	}
};

int _tmain(int argc, _TCHAR* argv[]){
	return 0;
}
