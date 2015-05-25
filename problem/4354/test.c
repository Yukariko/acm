#include <stdio.h>

int gcd(int p,int q){return q?gcd(q,p%q):p;}

int main()
{
	char a[1000001];
	int len;
	for(;len = strlen(gets(a)),*a != '.';)
	{
		int b[27] = {};
		
		for(int i=0;a[i];i++)
			b[a[i]-'a']++;
		
		int max = 0;
		for(int i=0;i<26;i++)
		{
			if(b[i])
			{
				if(!max)
					max = b[i];
				else
					max = gcd(max, b[i]);
			}
		}
		int ret = max;
		for(; ret > 1; ret--)
		{
			if(max % ret == 0)
			{
				int tok = len / ret;
				int find = 0;
				int seq = 0;
				for(int i=tok;a[i];i++)
				{
					if(a[i] != a[seq++])
					{
						find = 1;
						break;
					}
					if(seq == tok)
						seq = 0;
				}
				if(!find) break;
			}
		}
		printf("%d\n",ret);
	}
	return 0;	
}
