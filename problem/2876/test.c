main()
{
  int n;
  scanf("%d",&n);
  int grade[100001][2]={};
  int i,j,k;
  for(i=0;i<n;i++)
  {
    int p,q;
    scanf("%d%d",&grade[i][0],&grade[i][1]);
  }
  int max=0,s;
  for(i=1;i<=5;i++)
  {
    s=0;
    for(j=0;j<n;j++)
    {
      if(grade[j][0]==i||grade[j][1]==i)s++;
      else s=0;
      if(max<s)
      {
        max=s;
        k=i;
      }
    }
  }
  printf("%d %d",max,k);
}
