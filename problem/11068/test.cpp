#include <bits/stdc++.h>

using namespace std;

bool base(int N, int B)
{
	string a;
	while(N)
	{
		a += N % B;
		N /= B;
	}

	string b = a;
	reverse(a.begin(), a.end());
	return a == b;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);
		bool find = false;
		for(int i=2; i <= 64; i++)
			if(base(N,i))
			{
				find = true;
				break;
			}
		printf("%d\n",find);
	}
	return 0;
}