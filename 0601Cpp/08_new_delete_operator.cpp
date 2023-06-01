#include <iostream>

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x=0,int y=0) : xpos(x), ypos(y) {}

	friend ostream& operator << (ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

	// new : �޸� �Ҵ�, �ڷ����� ũ�⿡ �°�
	void* operator new(size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size]; // 1byte ������ �Ҵ�Ǳ� ����
		return adr;
	}

	void operator delete(void* adr)
	{
		cout << "operator delete()" << endl;
		delete[] adr; // �����Ϸ��� void* ������ ��� ���Ѵٸ� delete[]((char*)adr); �� ���
	}

	// �迭 ������ ���� �Ҵ�
	void* operator new[](size_t size)
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

		void operator delete[](void* adr)
	{
		cout << "operator delete[]" << endl;
		delete[] adr;
	}
};

int main()
{
	Point* ptr = new Point(3, 4); // ��ü ���� ���� new�� �ٷ� ����� ��. --> ���ʿ� new, delete�� static �Լ���.

	cout << *ptr;

	Point* arr = new Point[3];
	
	for (int i = 0; i < 3; i++)
	{
		arr[i] = *ptr;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i];
	}

	delete ptr;

	delete[] arr;

	return 0;
}