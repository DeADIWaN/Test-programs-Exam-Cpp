#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

class Monsters {
public:
	virtual void say() = 0;
	virtual ~Monsters() {};
};

class TypeA : public Monsters {
private:
	string word;
public:
	TypeA(string w) : word(w) {};
	void say() {
		cout << word << endl;
	}
	~TypeA() {
		word.clear();
	}
};

class TypeB : public Monsters {
private:
	string word;
public:
	TypeB(string w) : word(w) {};
	void say() {
		cout << word << " " << word << endl;
	}
	~TypeB() {
		word.clear();
	}
};

class TypeC : public Monsters {
private:
	string word;
public:
	TypeC(string w) : word(w) {};
	void say() {
		cout << word << " " << word << " " << word << endl;
	}
	~TypeC() {
		word.clear();
	}
};

int _tmain(int argc, _TCHAR* argv[]){
	string word;
	Monsters *m[] = { new TypeA(cin >> word), new TypeC(cin >> word), new TypeB(cin >> word), new TypeA(cin >> word) };
	for (int i = 0; i < 4; i++) {
		m[i]->say();
	}
	system("pause");
	return 0;
}
