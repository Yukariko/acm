main()
{
  int n;
  int a[5001];
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  int max=0,s;
  for(i=0;i<n;i++)
  {
    s=0;
    for(j=i,k=i+1;j>=0&&k<n;k++)
    {
      if(a[j]==a[k])
      {
        s+=2;
        j--;
      }
    }
    max=max<s?s:max;
    s=1;
    for(j=i-1,k=i+1;j>=0&&k<n;k++)
    {
      if(a[j]==a[k])
      {
        s+=2;
        j--;
      }
    }
    max=max<s?s:max;
  }
  printf("%d",n-max);
}
