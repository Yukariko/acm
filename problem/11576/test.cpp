#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A, B;
	scanf("%d%d",&A,&B);

	int ans = 0;

	int N;
	scanf("%d",&N);
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		ans *= A;
		ans += n;
	}

	vector<int> a;
	while(ans)
	{
		a.push_back(ans % B);
		ans /= B;
	}

	reverse(a.begin(), a.end());
	for(int i=0; i < a.size(); i++)
		printf("%d ", a[i]);
	return 0;
}