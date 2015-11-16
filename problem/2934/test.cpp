#include <bits/stdc++.h>

using namespace std;

#define MAX_L 100000
#define S 300

int pack[MAX_L / S + 1][2];
int a[MAX_L + 1][2];
int sub_plant[MAX_L + 1];

void update_start(int pos)
{
	a[pos][0]++;
	pack[pos/S][0]++;
}

void update_end(int pos)
{
	a[pos][1]++;
	pack[pos/S][1]++;
}

int find(int pos)
{
	int lb = pos / S;

	int ans = -a[pos][1] -sub_plant[pos];
	for(int i=0; i < lb; i++)
		ans += pack[i][0] - pack[i][1];

	lb *= S;
	int mod = pos % S;
	for(int i=0; i < mod; i++)
		ans += a[lb+i][0] - a[lb+i][1];

	sub_plant[pos] += ans;
	return ans;
}

int main()
{
	int N;
	scanf("%d",&N);

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n", find(l) + find(r));
		update_start(l);
		update_end(r);
	}
	return 0;
}