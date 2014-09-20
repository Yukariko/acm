find(n)
{
  return n/100;
}
main()
{
  int t;
  int a[200001];
  int b[100001];
  for(scanf("%d",&t);t--;)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,k,s=100000;
    int hund[2001]={};
    for(i=0;i<=s;i++)a[i]=0;
    for(i=1;i<=n;i++)
    {
      a[i+s]=1;
      if(i%100==0)
      {
        hund[i/100-1+1000]=i==100?99:100;
      }
      b[i]=i+s;
    }
    hund[n/100+1000]=n%100;
    for(i=0;i<m;i++)
    {
      scanf("%d",&k);
      int res=0;
      if(b[k]!=s+1)
      {
        int end=find(b[k]);
        for(j=0;j<end;j++)res+=hund[j];
        end=b[k]/100*100;
        for(j=b[k]-1;j>=end;j--)res+=a[j];
        a[b[k]]--;
        hund[find(b[k])]--;        
        b[k]=s--;
        a[b[k]]++;
        hund[find(b[k])]++;
      }
      printf("%d ",res);
    }
    puts("");
  }
}
