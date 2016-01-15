#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> part(N, -1), count(N, 0), release(N, -1);
	for(int i=0; i < M; i++)
	{
		int n;
		scanf("%d", &n);

		int sel = 0;
		for(int j=0; j < N; j++)
			if(part[j] == n)
			{
				sel = j;
				break;
			}
			else if(count[j] < count[sel])
				sel = j;
			else if(count[j] == count[sel] && release[j] < release[sel])
				sel = j;

		if(part[sel] == n)
			count[sel]++;
		else
		{
			part[sel] = n;
			count[sel] = 1;
			release[sel] = i;
		}
	}

	sort(part.begin(), part.end());
	for(int i=0; i < N; i++)
		printf("%d ", part[i]);
	return 0;
}