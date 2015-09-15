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
	long long p=1, q=0, r=2;
	cin >> N;
	if(N == 1)
	{
		cout << q;
		return 0;
	}
	if(N == 2)
	{
		cout << p;
		return 0;
	}
	for(int i=3; i <= N; i++)
	{
		r = p;
		p = (i - 1) * (p + q) % 1000000000;
		q = r;
	}
	cout << p;
	return 0;
}