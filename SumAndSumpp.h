using namespace std;

class Sum {
protected:
	int *value1, *value2;
public:
	Sum() {
		value1 = nullptr;
		value2 = nullptr;
	}
	Sum(int val1, int val2) {
		value1 = new int(val1);
		value2 = new int(val2);
	}
	Sum(const Sum &sum) {
		value1 = sum.value1 ? new int(*sum.value1) : nullptr;
		value2 = sum.value2 ? new int(*sum.value2) : nullptr;
	}
	~Sum() {
		if (value1)
			delete value1;
		if (value2)
			delete value2;
	}
	Sum& operator=(const Sum &sum) {
		if (value1 && sum.value1)
			*value1 = *sum.value1;
		else if (!value1 && sum.value1)
			value1 = new int(*sum.value1);
		else if (value1 && sum.value1)
			delete value1;

		if (value2 && sum.value2)
			*value2 = *sum.value2;
		else if (!value2 && sum.value2)
			value2 = new int(*sum.value2);
		else if (value2 && sum.value2)
			delete value2;
		return *this;
	}
	Sum& operator+(const Sum &sum) {
		Sum *newSum = new Sum(*this);
		if (newSum->value1 && sum.value1)
			*newSum->value1 += *sum.value1;
		else if (!newSum->value1 && sum.value1)
			newSum->value1 = new int(*sum.value1);
		if (newSum->value2 && sum.value2)
			*newSum->value2 += *sum.value2;
		else if (!newSum->value2 && sum.value2)
			newSum->value2 = new int(*sum.value2);
		return *newSum;
	}
};

class Sumpp : public Sum {
public:
	Sumpp() : Sum() {}
	Sumpp(int val1, int val2) : Sum(val1, val2) {};
	Sumpp(const Sumpp &sumpp) {
		value1 = sumpp.value1 ? new int(*sumpp.value1) : nullptr;
		value2 = sumpp.value2 ? new int(*sumpp.value2) : nullptr;
	};
	Sumpp& operator+(const Sumpp &sumpp) {
		Sumpp *newSum = new Sumpp(*this);
		if (newSum->value1 && sumpp.value1)
			*newSum->value1 += (*sumpp.value1 + 1);
		else if (!newSum->value1 && sumpp.value1)
			newSum->value1 = new int(*sumpp.value1 + 1);
		if (newSum->value2 && sumpp.value2)
			*newSum->value2 += (*sumpp.value2 + 1);
		else if (!newSum->value2 && sumpp.value2)
			newSum->value2 = new int(*sumpp.value2 + 1);
		return *newSum;
	}
};
