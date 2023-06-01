#include <iostream>

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}

	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	friend ostream& operator << (ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class SmartPtr // 포인터처럼 동작하는 클래스
{
	Point* posptr;

public:
	SmartPtr(Point* ptr) : posptr(ptr) {}

	Point& operator*() const
	{
		return *posptr;
	}

	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr()
	{
		delete posptr; // 생성자에서 new 연산이 됐다는 가정이 들어감, 스마트포인터 쓰는 가장 큰 이유
	}
};

int main()
{
	SmartPtr sptr1(new Point(1, 2)); // 매개변수에 바로 생성
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(3, 4));

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr1->SetPos(30, 40);
	sptr1->SetPos(50, 60);

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	return 0;
}