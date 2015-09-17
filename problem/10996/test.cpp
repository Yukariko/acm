#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for(int i=0; i < N * 2; i++)
	{
		if(i % 2)
		{
			cout << " ";
			for(int j=0; j < N / 2; j++)
				cout << "* ";
		}
		else
			for(int j=0; j < (N+1) / 2; j++)
				cout << "* ";

		cout << '\n';
	}

	return 0;
}