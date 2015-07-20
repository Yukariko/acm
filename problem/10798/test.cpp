#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	char a[5][16] = {};
	for(int i=0; i < 5; i++)
		cin >> a[i];

	for(int i=0; i < 15; i++)
		for(int j=0; j < 5; j++)
			if(a[j][i])
				cout << a[j][i];

	return 0;
}