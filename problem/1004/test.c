#include <stdio.h>
#include <math.h>

int main()
{
	int cnt;
	int x1, y1;
	int x2, y2;
	int spaceX[50];
	int spaceY[50];
	int spaceR[50];
	int i,k;
	long double distance_start;
	long double distance_end;
	int answer;
	scanf("%d", &cnt);
	while (cnt)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			scanf("%d %d %d", &spaceX[i], &spaceY[i], &spaceR[i]);
		}
		answer = 0;
		for (i = 0; i < k; i++)
		{
			distance_start = sqrt(pow((spaceX[i] - x1), 2) + pow((spaceY[i] - y1), 2));
			distance_end = sqrt(pow((spaceX[i] - x2), 2) + pow((spaceY[i] - y2), 2));
			if (spaceR[i] > distance_start)
				answer++;
			if (spaceR[i] > distance_end)
				answer++;
			if (spaceR[i] > distance_start && spaceR[i] > distance_end)
				answer-=2;
		}
		printf("%d\n", answer);
		cnt--;
	}
	return 0;
}
