#include <iostream>

// 포인터 연산자 오버로딩 * ->

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
		return this; // 주소값 리턴
	}

	// * --> 나 자신을 참조하자.
	Number& operator*()
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();

	*num = 30; // num.operator*() = 50; private 멤버변수를 변경할수 있어서 위험함 --> 10으로
	num.ShowData();
	num->ShowData(); // num.operator->()->showData();

	num.operator*() = 50;
	num.operator*().ShowData();

	return 0;
}