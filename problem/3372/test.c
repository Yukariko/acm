#include <stdio.h>
#include <string.h>

char *bigPlus(char *store,char *a,char *b)
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

int N;
int map[101][101];
char dp[101][101][101];

char* solve(int y,int x)
{
	if(y == N-1 && x == N-1)
		return "1";
	if(y < 0 || y >= N || x < 0 || x >= N || map[y][x] == 0)
		return "0";

	char *ret = dp[y][x];
	if(*ret)
		return ret;

	int jump = map[y][x];
	bigPlus(ret,solve(y+jump,x),solve(y,x+jump));
	return ret;
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d",&map[i][j]);

	printf("%s",solve(0,0));
	return 0;
}