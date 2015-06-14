#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	char a[1001][10];
	int left=0,right=0;
	int ret=0;

	scanf("%d ",&N);
	gets(a[right++]);
	N<<=1;
	while(--N)
	{
		gets(a[right]);
		while(a[left][0]==0)left++;
		if(strcmp(a[left],a[right]))
		{
			int find = 0;
			for(int j=left+1;j<right;j++)
			{
				if(strcmp(a[j],a[right])==0)
				{
					find = 1;
					a[j][0] = 0;
					ret++;
					break;
				}
			}
			if(!find)
				right++;
		}
		else
			a[left++][0] = 0;
	}
	printf("%d",ret);
	return 0;
}
