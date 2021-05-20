#pragma once
#include <vector>
#include <iostream>
#include <string>

class uli //unsigned long int
{
private:
	static const int BASE = 1000000000;
	std::vector <int> number;
	static std::vector <int> min(std::vector <int>, std::vector <int>);
	static std::vector <int> max(std::vector <int>, std::vector <int>);
	static int getNum(int, int);
	static int to_int(std::string, int);
public:
	uli()
	{
		number.push_back(0);
	}
	uli(int value)
	{
		number.push_back(value);
		if (number[0] >= uli::BASE)
		{
			int rem = number[0] / uli::BASE;
			number[0] %= uli::BASE;
			number.push_back(rem);
		}
	}
	uli(std::string value)
	{
		if (value.size() > 9)
		{
			for (int i = (value.size() - 1) / 9; i >= 0; i--)
			{
				int start = (value.size() - i * 9) - 9;
				(start > 0) ? start : start = 0;
				std::string temp = value.substr(start, (value.size() - i * 9) - start);
				number.insert(number.begin(), uli::to_int(temp, temp.size()));
			}
		}
		else { number.push_back(to_int(value, value.size())); }
	}
	int getNumberOfNums();
	friend std::ostream& operator << (std::ostream&, uli);
	friend uli operator + (uli, uli);
	friend uli& operator ++ (uli&, int);
	friend void operator += (uli&, uli);
	friend bool operator > (uli, uli);
	friend bool operator < (uli, uli);
	friend bool operator >= (uli, uli);
	friend bool operator <= (uli, uli);
	friend bool operator == (uli, uli);
	friend bool operator != (uli, uli);
	int operator = (int a)
	{
		number.clear();
		number.push_back(a);
		if (number[0] >= uli::BASE)
		{
			int rem = number[0] / uli::BASE;
			number[0] %= uli::BASE;
			number.push_back(rem);
		}
		return a;
	}
};