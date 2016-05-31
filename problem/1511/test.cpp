#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[10];
	int sum = 0;
	for(int i=0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	bool lead = true;
	int postSel = -1;
	while(sum--)
	{
		int maxNum = -1, maxCnt = 0;
		for(int i=0; i < 10; i++)
		{
			if(i == postSel)
				continue;
			if(a[i])
				maxNum = i;
			if(a[maxCnt] < a[i])
				maxCnt = i;
		}

		if(maxNum == -1)
			break;

		int sel = maxNum;
		if(a[maxCnt] * 2 > sum + 1)
			sel = maxCnt;

		a[sel]--;
		if(!lead || sel)
			printf("%d", sel);
		if(lead && sel)
			lead = false;
		postSel = sel;
	}

	if(lead)
		printf("0");
	return 0;
}