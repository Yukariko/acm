#include <bits/stdc++.h>

using namespace std;

char *bigplus(char *store,char *a,char *b)
{
	char t[1001]={0};
	int i=strlen(a),j=strlen(b),p,s;
	for(p=0;i||j;p++)
	{
		s = (i?a[i-1]-'0':0)+(j?b[j-1]-'0':0);
		if(s+t[p]>9)t[p+1]+=(s+t[p])/10;
		t[p] = (s+t[p])%10;
		if(i>0)i--;
		if(j>0)j--;
	}
	if(!t[p])p--;
	for(i=0;i<=p;i++)
	 store[p-i]=t[i]+'0';
	store[p+1]=0;
	return store;
}

int main()
{
	int N;
	scanf("%d",&N);

	char a[1001] = "1";
	char b[1001] = "1";
	
	while(--N)
	{
		char c[1001];
		memcpy(c, a, sizeof(a));
		bigplus(a, a, b);
		memcpy(b, c, sizeof(c));
	}

	puts(b);
	return 0;
}