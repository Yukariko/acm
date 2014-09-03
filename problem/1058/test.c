main()
{
  int friend[51][51]={};
  int friend2[51][51]={};
  char a[52];
  int n;
  scanf("%d ",&n);
  int i,j,k;
  for(i=1;i<=n;i++)
  {
    gets(a+1);
    for(j=1;a[j];j++)
    {
      friend[i][j]=a[j]=='Y'?1:0;
      friend[j][i]=a[j]=='Y'?1:0;
    }
  }
  int max=0;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(i!=j&&friend[i][j])
      {
        friend2[i][j]=1;
        for(k=1;k<=n;k++)if(i!=k&&j!=k&&friend[j][k])friend2[i][k]=1;
      }
    }
    int s=0;
    for(j=1;j<=n;j++)s+=friend2[i][j];
    max=max<s?s:max;
  }
  printf("%d",max);
}
