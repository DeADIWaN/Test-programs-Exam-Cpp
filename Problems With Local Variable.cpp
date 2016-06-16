#include "stdafx.h"
#include "iostream"

using namespace std;

class Sum {
	int *a, *b;
public:
	Sum(int x, int y) {
		a = &x;
		b = &y;
	}
};

int _tmain(int argc, _TCHAR* argv[]){
	Sum a(7, 8);
	return 0;
}
