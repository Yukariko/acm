#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool numSet[1001] = {};
	vector<int> primeSet;

	for(int i=2; i <= 1000; i++)
	{
		if(numSet[i] == false)
		{
			primeSet.push_back(i);
			for(int j=i*i; j <= 1000; j += i)
				numSet[j] = true;
		}
	}

	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		bool find = false;

		for(size_t i=0; i < primeSet.size(); i++)
		{
			for(size_t j=i; j < primeSet.size(); j++)
			{
				if(primeSet[i] + primeSet[j] + 3 == N)
				{
					int ans[] = {primeSet[i], primeSet[j], 3};
					sort(ans, ans + 3);
					printf("%d %d %d\n", ans[0], ans[1], ans[2]);
					find = true;
					break;
				}
			}
			if(find)
				break;
		}
	}
	return 0;
}