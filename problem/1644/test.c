char che[4000001];
int prime[283147];
main()
{
  long long i,j,k=0;
  int n;
  scanf("%d",&n);
  for(i=2;i<=n;i++)
  {
    if(che[i]==0)
    {
      prime[k++]=i;
      for(j=i*i;j<=n;j+=i)che[j]=1;
    }
  }
  int s=0,t;
  for(i=0;i<k;i++)
  {
    t=prime[i];
    for(j=i+1;t<n;t+=prime[j++]);
    if(t==n)s++;
  }
  printf("%d",s);
}
