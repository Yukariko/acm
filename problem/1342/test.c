#include <stdio.h>

char a[11];
char visit[27];
int len;
int solve(int pos,int before)
{
	if(pos == len)
		return 1;

	int ret = 0;

	for(char i = 0; i < 26; i++)
	{
		if(visit[i] && i != before)
		{
			visit[i]--;
			ret += solve(pos+1,i);
			visit[i]++;
		}
	}
	return ret;
}

int main()
{
	len = strlen(gets(a));
	for(int i=0;i<len;i++)
		visit[a[i]-'a']++;
	printf("%d",solve(0,-1));
	return 0;
}