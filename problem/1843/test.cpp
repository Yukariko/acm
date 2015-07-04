#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	long long ret = 0;
	for(int i=N-2; i > 0; i-=2)
		ret += i;

	cout << ret << endl;

	ret = 0;
	int factor[5000];
	int fCnt = 0;
	for(int i=1; i*i <= N; i++)
	{
		if(N % i == 0)
		{
			factor[fCnt++] = i;
			if(N / i != i)
				factor[fCnt++] = N / i;
		}
	}

	sort(factor, factor + fCnt);

	for(int i=0; i < fCnt; i++)
		for(int j=i; j < fCnt; j++)
			for(int k=j+1; k < fCnt; k++)
				if(factor[i] + factor[j] == factor[k])
					ret++;

	cout << ret << endl;

	char che[500001] = {};
	int prime[42001];
	int pCnt = 0;
	for(long long i=2; i <= N; i++)
	{
		if(che[i] == 0)
		{
			prime[pCnt++] = i;
			for(long long j=i*i; j <= N; j+=i)
				che[j] = 1;
		}
	}

	ret = 0;
	for(int i=0; i < pCnt; i++)
		for(int j=i; j < pCnt && prime[i] + prime[j] <= N; j++)
			if(!che[prime[i] + prime[j]])
				ret++;
	cout << ret << endl;

	return 0;
}