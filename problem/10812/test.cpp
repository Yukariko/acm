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
		int p,q,r;
		cin >> p >> q >> r;
		
		int b[101];

		for(int j=p; j <= q; j++)
			b[j] = a[j];

		int pos = 0;
		while(r+pos <= q)
		{
			a[p+pos] = b[r+pos];
			pos++;
		}

		for(int j=p; j < r; j++)
			a[p+pos++] = b[j];
	}

	for(int i=1; i <= N; i++)
		cout << a[i] << " ";
	return 0;
}