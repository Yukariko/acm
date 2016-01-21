#include <bits/stdc++.h>

using namespace std;

char a[51];

bool chance;
int cl, cr;
int cache[51][51];

int solve(int left, int right)
{
	if(left >= right)
		return 0;

	int& ans = cache[left][right];
	if(ans != -1)
		return ans;

	ans = 987654321;
	char p = a[left];
	if(chance)
		p = left == cl? a[cr]: left == cr? a[cl] : p;

	char q = a[right];
	if(chance)
		q = right == cl? a[cr]: right == cr? a[cl] : q;

	if(p == q)
		ans = min(ans, solve(left + 1, right - 1));

	// 교환
	ans = min(ans, 1 + solve(left + 1, right - 1));

	// 삭제
	ans = min(ans, 1 + solve(left + 1, right));
	ans = min(ans, 1 + solve(left, right - 1));

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int len = strlen(gets(a));
	int ans = solve(0, len-1);
	chance = true;
	for(int i=0; i < len; i++)
		for(int j=i+1; j < len; j++)
		{
			cl = i;
			cr = j;
			memset(cache, -1, sizeof(cache));
			ans = min(ans, 1 + solve(0, len-1));
		}
	printf("%d", ans);
	return 0;
}