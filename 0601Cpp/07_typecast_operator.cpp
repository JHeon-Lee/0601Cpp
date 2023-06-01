#include <iostream>

// ����ȯ ������ �����ε�

using namespace std;

class Won
{
	int value = 0;

public:
	Won(int value = 0) : value(value) {}

	operator int() // ���ϴ� ����ȯ ����
	{
		return value;
	}
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
	float x;
	float y;
	float z;

public:
	Point(float x, float y, float z) : x(x), y(y), z(z) {}

	operator float* () // �迭�� �������� �̿� ����
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}

#pragma region �ú��ʹи� ����ȯ
class Minute
{
	int minute;

public:
	Minute(int minute = 0) : minute(minute) {}

	friend ostream& operator << (ostream& out, const Minute m)
	{
		out << m.minute;
		return out;
	}
};

class Second
{
	int second;

public:
	Second(int second = 0) : second(second) {}

	friend ostream& operator << (ostream& out, const Second s)
	{
		out << s.second;
		return out;
	}
};

class MiliSecond
{
	int milisecond;

public:
	MiliSecond(int milisecond = 0) : milisecond(milisecond) {}

	friend ostream& operator << (ostream& out, const MiliSecond m)
	{
		out << m.milisecond;
		return out;
	}
};

class Hour // ���⼭�� �����ε�
{
	int hour;

public:
	Hour(int hour = 0) : hour(hour) {}

	operator int()
	{
		return hour;
	}

	operator Minute()
	{
		return hour * 60;
	}

	operator Second()
	{
		return hour * 60 * 60;
	}

	operator MiliSecond()
	{
		return hour * 60 * 60 * 1000;
	}

	friend ostream& operator << (ostream& out, const Hour h)
	{
		out << h.hour;
		return out;
	}
};

void PrintHour(Hour hour)
{
	cout << hour << endl;
}

void PrintMinute(Minute minute)
{
	cout << minute << endl;
}

void PrintSecond(Second second)
{
	cout << second << endl;
}

void PrintMiliSecond(MiliSecond milisecond)
{
	cout << milisecond << endl;
}
#pragma endregion

int main()
{
	Won w(10);

	Print(1);
	// Print(w); �̷��� ����ϰ� ���� �� ����ȯ �����ε� �ʿ�
	Print(w);

	Point p(1.0f, 2.0f, 3.0f);

	PrintPoint(p);

	Hour h(1);
	PrintHour(h); // 1
	PrintMinute(h); // 60
	PrintSecond(h); // 60 * 60
	PrintMiliSecond(h); // 60 * 60 * 1000 ���ϱ���

	return 0;
}