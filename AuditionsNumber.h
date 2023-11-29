#pragma once

// количество прослушиваний
class AuditionsNumber
{
private:
	int count;

public:
	AuditionsNumber(int count = 0);

	void setCount(int count);
	int getCount();
	int addCount(int plusCount);

	int operator++();
	int operator++(int d);
};