#include <iostream>
#include <vector>
#include <algorithm>
#include "uli.h"

using namespace std;

uli fib(int indexF, vector <uli>& knownFib)
{
	static int maxIndex = 2;
	if (knownFib[indexF] != 0)
	{
		maxIndex = max(maxIndex, indexF);
		return knownFib[indexF];
	}
	for (int i = maxIndex; i <= indexF; i++)
	{
		if (knownFib[i] == 0) { knownFib[i] = knownFib[i - 1] + knownFib[i - 2]; }
	}
	return knownFib[indexF];
}

int main()
{
	int maxNumberOf;
	cin >> maxNumberOf;
	vector <uli> stor(maxNumberOf + 1);
	stor[1] = 1;
	stor[2] = 1;
	while (true)
	{
		int indexFib;
		cin >> indexFib;
		cout << fib(indexFib, stor) << endl;
	}
	return 0;
}