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
	
	for(int i=0; i < N; i++)
	{
		if(i % 2)
			cout << " ";
		for(int j=0; j < N; j++)
			cout << "* ";
		cout << '\n';
	}

	return 0;
}