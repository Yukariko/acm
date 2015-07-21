#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int a[101] = {};
	for(int i=0; i < M; i++)
	{
		int p,q,r;
		cin >> p >> q >> r;
		while(p <= q)
			a[p++] = r;
	}

	for(int i=1; i <= N; i++)
		cout << a[i] << " ";
	return 0;
}