#pragma once

// ���������� �������������
class AuditionsNumber
{
	int count;

	AuditionsNumber(int count = 0);

	void setCount(int count);
	int getCount();
	int addCount(int plusCount);

	int operator++();
	int operator++(int d);
};