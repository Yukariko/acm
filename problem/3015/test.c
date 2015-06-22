#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N;
	int a[500001];
	int b[500001];
	int v[500001]={};
	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);

	int max = a[0];
	long long ret = 0;

	int eq = 0;

	b[0] = -1;
	for(int i=1,j;i<N;i++)
	{
		b[i] = 0;
		for(j = i-1;; j = b[j])
		{
			if(a[j] <= a[i])
				ret += v[j] + 1;
			else
				ret += 1;
			if(b[i] == 0 && a[j] == a[i])
				b[i] = j;
			if(a[j] > a[i] || b[j] == -1)
				break;
		}
		if(max < a[i])
		{
			max = a[i];
			b[i] = -1;
		}
		else if(b[i] == 0)
			b[i] = j;
		else
		{
			int k,cnt = 0;
			for(k = b[i]; k != -1 && a[b[i]] == a[k]; k = b[k])
				cnt += v[k]+1;
			if(cnt)
			{
				b[i] = k;
				v[i] = cnt;
			}
		}
	}
	printf("%lld",ret);
	return 0;
}