#include <stdio.h>

int gcd(int a,int b){return a?gcd(a,b%a):b;}

int N;
int a[101];
int v[101][78500];
int prime[78499];
int pCount;
int merge[78500];
char che[1000001];

int solve()
{
  int ret = 1;
  
  for(int i=0;i<pCount;i++)
  {
    if(merge[i])
    {
      merge[i] /= N;
      for(int j=0;j<merge[i];j++)
        ret *= prime[i];
    }
  }
  return ret;
}

int solve2()
{
  int ret = 0;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<pCount;j++)
    {
      if(merge[j] && v[i][j] < merge[j])
        ret += merge[j] - v[i][j];
    }
  }
  
  return ret;
}


int main()
{
  
  for(long long i = 2; i <= 1000000; i++)
  {
    if(che[i] == 0)
    {
      prime[pCount++] = i;
      for(long long j = i*i; j <= 1000000; j+= i)
        che[j] = 1;
    }
  }
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
    for(int t = a[i], j = 0; t > 1;)
    {
      if(t % prime[j] == 0)
      {
        v[i][j]++;
        t /= prime[j];
        merge[j]++;
      }
      else
        j++;
    }
  }
  
  int score = solve();
  int count = solve2();
  
  printf("%d %d",score,count);
  return 0;
}
