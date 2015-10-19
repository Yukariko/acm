#include <bits/stdc++.h>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daySum[14];

int getDays(int month, int day)
{
	return daySum[month] + day;
}

int main()
{
	daySum[0] = 0;
	for(int i=1; i <= 13; i++)
		daySum[i] = daySum[i-1] + days[i-1];

	int start = getDays(3, 1);
	int end = getDays(11, 30);

	int N;
	scanf("%d",&N);

	vector<pair<int,int>> a;
	for(int i=0; i < N; i++)
	{
		int pm, pd, qm, qd;
		scanf("%d%d%d%d",&pm,&pd,&qm,&qd);

		pd = getDays(pm,pd);
		qd = getDays(qm,qd);

		if(qd < start || pd > end)
			continue;
		a.push_back({pd, qd});
	}

	int ans = 0;
	for(int i=start; i <= end; )
	{
		int mi = i;
		int sel = -1;
		for(int j=0; j < N; j++)
		{
			if(a[j].first <= i && a[j].second > mi)
			{
				mi = a[j].second;
				sel = j;
			}
		}

		if(sel == -1)
		{
			ans = 0;
			break;
		}
		
		ans++;
		i = mi;
	}
	printf("%d",ans);
	return 0;
}