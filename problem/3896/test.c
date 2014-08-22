main()
{
  char che[1299710]={0};
  int prime[100001];
  long long i,j;
  int k=0;
  for(i=2;i<=1299709;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=1299709;j+=i)che[j]=1;
    }
  }
  int t;
  for(scanf("%d",&t);t--;)
  {
    int p;
    scanf("%d",&p);
    int i;
    for(i=0;prime[i]<p;i++);
    printf("%d\n",prime[i]==p?0:i==0?2:prime[i]-prime[i-1]);
  }
}
