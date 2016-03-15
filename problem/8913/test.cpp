#include <bits/stdc++.h>

using namespace std;

char a[26];
int group[26];
int gcnt;
int tc=1;
short visit[1<<25];

bool solve(int mask)
{
	if(mask == 0)
		return true;

	if(visit[mask] == tc)
		return false;
	visit[mask] = tc;

	for(int i=0; i < gcnt; i++)
	{
		if((mask & (1 << i)) && group[i] >= 2)
		{
			int idxr = i+1;
			while(idxr < gcnt && !(mask & (1 << idxr)))
				idxr++;

			int idxl = i-1;
			while(idxl >= 0 && !(mask & (1 << idxl)))
				idxl--;

			if(idxl >= 0 && idxr < gcnt)
			{
				group[idxl] += group[idxr];
				mask ^= (1 << idxr);
			}

			if(solve(mask - (1 << i)))
				return true;

			if(idxl >= 0 && idxr < gcnt)
			{
				group[idxl] -= group[idxr];
				mask |= (1 << idxr);
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", a);
		group[0] = 1;
		gcnt = 0;
		for(int i=1; a[i]; i++)
		{
			if(a[i-1] != a[i])
			{
				gcnt++;
				group[gcnt] = 0;
			}
			group[gcnt]++;
		}
		gcnt++;
		printf("%d\n", solve((1 << gcnt) - 1));
		tc++;
	}
	return 0;
}