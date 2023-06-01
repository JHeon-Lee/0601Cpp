#include <iostream>

// ������ ������ �����ε� * ->

using namespace std;

class Number
{
	int num;

public:
	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	// ->
	Number* operator->()
	{
		return this; // �ּҰ� ����
	}

	// * --> �� �ڽ��� ��������.
	Number& operator*()
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();

	*num = 30; // num.operator*() = 50; private ��������� �����Ҽ� �־ ������ --> 10����
	num.ShowData();
	num->ShowData(); // num.operator->()->showData();

	num.operator*() = 50;
	num.operator*().ShowData();

	return 0;
}