#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define NUM 1000001

int main()
{
	bool numSet[NUM] = {};
	vector<int> primeSet;

	for(long long i=2; i < NUM; i++)
	{
		if(numSet[i] == false)
		{
			primeSet.push_back(i);
			for(long long j = i * i; j < NUM; j+=i)
				numSet[j] = true;
		}
	}

	int T;
	scanf("%d",&T);

	for(int tc = 1; tc <= T; tc++)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		vector<int> factor;

		char A[NUM] = {};
		char B[NUM] = {};

		for(int i=0; i < N; i++)
		{
			int p;
			scanf("%d",&p);
			for(int j=0; p > 1; j++)
			{
				if(numSet[p] == false)
				{
					A[p]++;
					factor.push_back(p);
					break;
				}
				while(p % primeSet[j] == 0)
				{
					A[primeSet[j]]++;
					p /= primeSet[j];
					factor.push_back(primeSet[j]);
				}
			}
		}

		for(int i=0; i < M; i++)
		{
			int p;
			scanf("%d",&p);
			for(int j=0; p > 1; j++)
			{
				if(numSet[p] == false)
				{
					B[p]++;
					factor.push_back(p);
					break;
				}
				while(p % primeSet[j] == 0)
				{
					B[primeSet[j]]++;
					p /= primeSet[j];
					factor.push_back(primeSet[j]);
				}
			}
		}
		sort(factor.begin(), factor.end());

		int P=1, Q=1;

		int sel = -1;
		for(vector<int>::iterator it=factor.begin(); it != factor.end(); ++it)
		{
			if(sel == *it)
				continue;
			sel = *it;

			int overlap = min(A[*it], B[*it]);

			A[*it] -= overlap;
			B[*it] -= overlap;

			for(int i=0; i < A[*it]; i++)
				P *= *it;

			for(int i=0; i < B[*it]; i++)
				Q *= *it;
		}
		printf("Case #%d: %d / %d\n",tc,P,Q);
	}
	return 0;
}