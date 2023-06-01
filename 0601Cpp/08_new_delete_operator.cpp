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

	// new : 메모리 할당, 자료형의 크기에 맞게
	void* operator new(size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size]; // 1byte 단위로 할당되기 때문
		return adr;
	}

	void operator delete(void* adr)
	{
		cout << "operator delete()" << endl;
		delete[] adr; // 컴파일러가 void* 연산을 허용 안한다면 delete[]((char*)adr); 로 사용
	}

	// 배열 형식의 동적 할당
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
	Point* ptr = new Point(3, 4); // 객체 생성 전에 new가 바로 사용이 됨. --> 애초에 new, delete는 static 함수라서.

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