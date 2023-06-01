#include <iostream>

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point ��ü ����" << endl;
	}

	~Point()
	{
		cout << "Point ��ü �Ҹ�" << endl;
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

class SmartPtr // ������ó�� �����ϴ� Ŭ����
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
		delete posptr; // �����ڿ��� new ������ �ƴٴ� ������ ��, ����Ʈ������ ���� ���� ū ����
	}
};

int main()
{
	SmartPtr sptr1(new Point(1, 2)); // �Ű������� �ٷ� ����
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