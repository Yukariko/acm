#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a[201] = {};

	int N;
	cin >> N;

	for(int i=0; i < N; i++)
	{
		int p;
		cin >> p;
		a[p+100]++;
	}

	int f;

	cin >> f;

	cout << a[f+100];
	return 0;
}