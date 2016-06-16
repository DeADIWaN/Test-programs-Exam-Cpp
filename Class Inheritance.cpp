//Ќаписать "базовый" класс с двум€ пол€ми, которые €вл€ютс€ указател€ми на int, ќписать конструктор, деструктор дл€ данного класса. —оздать класс наследник от базового класса с одним дополнительным новым полем. ƒолжна быть возможность создавать объекты класса наследника.
#include "stdafx.h"
#include "iostream"

using namespace std;

class First {
protected:
	int *a, *b;
public:
	First() {
		a = nullptr;
		b = nullptr;
	}
	First(int v1, int v2) {
		a = new int(v1);
		b = new int(v2);
	}
	~First() {
		if (a != nullptr) {
			delete a;
		}
		if (b != nullptr) {
			delete b;
		}
	}
};

class Second: public First {
	int *c;
public:
	Second() : First() {
		c = nullptr;
	}
	Second(int v1, int v2) : First (v1, v2) {
		c = new int(*a + *b);
	}
	~Second() {
		if (c != nullptr) {
			delete c;
		}
	}
	void say() {
		cout << *a << endl << *b << endl << *c << endl;
	}
};



int _tmain(int argc, _TCHAR* argv[]){
	First Pustoj;
	Second Pustoy;
	First A1(4, 5);
	Second A2(8, 9);
	A2.say();
	return 0;
}
