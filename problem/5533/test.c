main()
{
  int n;
  scanf("%d",&n);
  int i,j,k;
  int a[201][4];
  for(i=0;i<n;i++)
  {
    scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
  }
  int score[201]={};
  for(j=0;j<3;j++)
  {
    for(i=0;i<n;i++)
    {
      for(k=0;k<n;k++)
      {
        if(i!=k&&a[i][j]==a[k][j])break;
      }
      if(k==n)score[i]+=a[i][j];
    }
  }
  for(i=0;i<n;i++)printf("%d\n",score[i]);
}
