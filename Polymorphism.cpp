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

int _tmain(int argc, _TCHAR* argv[]) {
	string word[4];
	for (int i = 0; i < 4; i++) {
		cin >> word[i];
	}
	Monsters *m[] = { new TypeA(word[0]), new TypeC(word[1]), new TypeB(word[2]), new TypeA(word[3]) };
	for (int i = 0; i < 4; i++) {
		m[i]->say();
	}
	system("pause");
	return 0;
}
