char map[51][13];
int n;
long long point[10];
int sel[10];
int front[10];
long long f()
{
  int i,j;
  long long t,s=0;
  for(i=0;i<n;i++)
  {
    for(t=j=0;map[i][j];j++)
    {
      t=t*10+sel[map[i][j]-'A'];
    }
    s+=t;
  }
  return s;
}
main()
{
  scanf("%d ",&n);
  int i,j;
  for(i=0;i<n;i++)
  {
    long long k=1;
    for(j=strlen(gets(map[i]))-1;j>=0;j--)
    {
      point[map[i][j]-'A']+=k;
      k*=10;
    }
    front[map[i][0]-'A']++;
  }
  for(i=0;i<10;i++)if(point[i]==0)break;
  if(i==10)
  {
    int min=-1;
    for(i=0;i<10;i++)
    {
      if(front[i]==0)
      {
        if(min==-1)min=i;
        else min=point[min]>point[i]?i:min;
      }
    }
    sel[min]=0;
    point[min]=-1;
  }
  for(i=9;i>=1;i--)
  {
    long long max=0;
    for(j=0;j<10;j++)
    {
      max=point[max]<point[j]?j:max;
    }
    if(point[max]!=-1)
    {
      sel[max]=i;
      point[max]=-1;
    }
  }
  printf("%lld",f());
}
