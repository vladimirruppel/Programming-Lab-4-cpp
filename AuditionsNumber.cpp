#include "AuditionsNumber.h"

AuditionsNumber::AuditionsNumber(int count)
{
	this->count = count;
}

void AuditionsNumber::setCount(int count)
{
	this->count = count;
}

int AuditionsNumber::getCount()
{
	return count;
}

int AuditionsNumber::addCount(int plusCount)
{
	count = count + plusCount;
	return count;
}

int AuditionsNumber::operator++()
{
	return addCount(1);
}

int AuditionsNumber::operator++(int d)
{
	return addCount(1);
}
