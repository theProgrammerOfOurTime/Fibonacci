#include "uli.h"
#include <string>
#include <algorithm>

std::vector <int> uli::min(std::vector <int> a, std::vector <int> b)
{
	return (a.size() > b.size()) ? b : a;
}

std::vector <int> uli::max(std::vector <int> a, std::vector <int> b)
{
	return (a.size() <= b.size()) ? b : a;
}

int uli::getNum(int value, int number)
{
	return ((value % int(std::pow(10, number))) - (value % int(std::pow(10, number - 1)))) / int(pow(10, number - 1));
}

int uli::getNumberOfNums()
{
	return std::to_string(number[number.size() - 1]).size() + 9 * (number.size() - 1);
}

int uli::to_int(std::string str, int base)
{
	if (base == 1) { return str.at(0) - '0'; }
	return (str.at(0) - '0') * int(std::pow(10, base - 1)) + to_int(str.substr(1, str.size()), base - 1);
}

void operator += (uli& a, uli b)
{
	a = a + b;
}

uli& operator ++ (uli& a, int value)
{
	a = a + 1;
	return a;
}

bool operator != (uli a, uli b)
{
	return !(a == b);
}

bool operator == (uli a, uli b)
{
	return !(a > b || a < b);
}

bool operator >= (uli a, uli b)
{
	return !(a < b);
}

bool operator <= (uli a, uli b)
{
	return !(a > b);
}

bool operator < (uli a, uli b)
{
	if (a.getNumberOfNums() < b.getNumberOfNums()) { return true; }
	else if (a.getNumberOfNums() != b.getNumberOfNums()) { return false; }
	for (int i = a.number.size() - 1; i >= 0; i--)
	{
		if (a.number[i] != b.number[i] && a.number[i] < b.number[i]) { return true; }
	}
	return false;
}

bool operator > (uli a, uli b)
{
	if (a.getNumberOfNums() > b.getNumberOfNums()) { return true; }
	else if (a.getNumberOfNums() != b.getNumberOfNums()) { return false; }
	for (int i = a.number.size() - 1; i >= 0; i--)
	{
		if (a.number[i] != b.number[i] && a.number[i] > b.number[i]) { return true; }
	}
	return false;
}

uli operator + (uli a, uli b)
{
	uli result;
	std::vector <int> minMumber = uli::min(a.number, b.number);
	result.number = uli::max(a.number, b.number);
	for (int i = minMumber.size() - 1; i >= 0; i--)
	{
		result.number[i] += minMumber[i];
		if (result.number[i] >= uli::BASE)
		{
			int rem = result.number[i] / uli::BASE;
			result.number[i] %= uli::BASE;
			if (i + 1 != result.number.size()) { result.number[i + 1] += rem; }
			else { result.number.push_back(rem); }
		}
	}
	return result;
}

std::ostream& operator << (std::ostream& f, uli number)
{
	f << number.number[number.number.size() - 1];
	for (int i = number.number.size() - 2; i >= 0; i--)
	{
		std::string temp = "000000000";
		std::string temp2 = std::to_string(number.number[i]);
		for (int j = 0; j < temp2.size(); j++)
		{
			temp.at(temp.size() - j - 1) = temp2.at(temp2.size() - j - 1);
		}
		f << temp;
	}
	return f;
}