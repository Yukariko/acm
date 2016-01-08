#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	sort(a.begin(), a.end());

	long long left = 0, right = (long long)a.back() * M;
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		
		int people = M;
		for(int i=0; i < N && people > 0; i++)
			people -= mid / a[i];

		if(people <= 0)
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%lld", left);
	return 0;
}