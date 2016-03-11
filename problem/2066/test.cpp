#include <bits/stdc++.h>

using namespace std;

char a[9][5][3];
int hexPos[10];
double cache[1953126];

char num(int mask, int idx)
{
	int n = (mask / hexPos[idx]) % 5;
	if(n == 0)
		return '5' - idx;
	return a[idx][4 - n][0];
}

int sub(int mask, int p, int q)
{
	int pn = (mask / hexPos[p]) % 5;
	int qn = (mask / hexPos[q]) % 5;

	mask -= pn * hexPos[p];
	mask -= qn * hexPos[q];
	mask += (pn - 1) * hexPos[p];
	mask += (qn - 1) * hexPos[q];
	return mask;
}

double solve(int pos, int mask)
{
	if(mask == 0)
		return 1.0;

	double& ans = cache[mask];
	if(ans != -1.0)
		return ans;

	ans = 0;
	int cnt = 0;
	for(int i=0; i < 9; i++)
	{
		for(int j=i+1; j < 9; j++)
		{
			if(num(mask, i) == num(mask, j))
			{
				cnt++;
				ans += solve(pos + 1, sub(mask, i, j));
			}
		}
	}

	if(cnt == 0)
		return ans;

	ans /= cnt; 
	return ans;
}

int main()
{
	fill(&cache[0], &cache[1953126], -1.0);
	for(int i=0; i < 9; i++)
		for(int j=0; j < 4; j++)
			scanf("%s", a[i][3-j]);

	hexPos[0] = 1;
	for(int i=1; i < 10; i++)
		hexPos[i] = hexPos[i-1] * 5;

	printf("%.6f", solve(0, hexPos[9] - 1));
	return 0;
}