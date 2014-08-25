main()
{
  int n;
  int a[100001];
  int count[100001];
  scanf("%d",&n);
  int k,j=0;
  for(int i=0;i<n;i++)
  {
    scanf("%d",&k);
    if(j>0&&k==a[j-1])count[j-1]++;
    else
    {
      count[j]=1;
      a[j++]=k;
    }
  }
  int max=0,cnt=count[0];
  for(int i=1;i<j;i++)
  {
    if(a[i-1]<a[i])
    {
      cnt+=count[i];
    }
    else
    {
      max=max<cnt?cnt:max;
      cnt=count[i];
    }
  }
  max=max<cnt?cnt:max;
  cnt=count[0];
  for(int i=1;i<j;i++)
  {
    if(a[i-1]>a[i])
    {
      cnt+=count[i];
    }
    else
    {
      max=max<cnt?cnt:max;
      cnt=count[i];
    }
  }
  max=max<cnt?cnt:max;
  printf("%d",max);
}
