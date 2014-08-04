int nan[10];
int visit[10];
int i;
find(c,s)
{
  int j;
  if(c==7&&s==100)
  {
    for(j=0;j<9;j++)
    {
      if(visit[j])printf("%d\n",nan[j]);
    }
    exit(0);
  }
  for(j=0;j<9;j++)
  {
    if(!visit[j])
    {
      visit[j]=1;
      find(c+1,s+nan[j]);
      visit[j]=0;
    }
  }
}
int cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
main()
{
  for(i=0;i<9;scanf("%d",nan+i++));
  qsort(nan,9,4,cmp);
  for(i=8;i>=0;i--)
  {
    if(nan[i]+nan[0]>97)visit[i]=1;
  }
  find(0,0);
}
