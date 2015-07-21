#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int a[101];
	for(int i=1; i <= N; i++)
		a[i] = i;

	for(int i=0; i < M; i++)
	{
		int p,q;
		cin >> p >> q;
		reverse(a+p, a+q+1);
	}

	for(int i=1; i <= N; i++)
		cout << a[i] << " ";
	return 0;
}