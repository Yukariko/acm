#include <bits/stdc++.h>

using namespace std;

int N;
int a[9];
map<int, double> check;

double solve()
{
	int mask = 0;
	for(int i=0; i < N; i++)
		mask = mask * 10 + a[i];
	if(check.count(mask))
		return check[mask];

	double& ans = check[mask];
	int cnt = 0;

	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			if(a[i] > a[j])
			{
				cnt++;
				swap(a[i], a[j]);
				ans += 1 + solve();
				swap(a[i], a[j]);
			}

	if(!cnt)
		return 0;
	return ans /= cnt;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	printf("%.10f", solve());
	return 0;
}