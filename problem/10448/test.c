main()
{
  int T;
  int tri[50];
  int res[1001][4]={};
  int i,j,k,l;
  
  for(i=1;(tri[i] = i*(i+1)/2) <= 1000; i++);
  k=i;
  
  res[0][0]=1;
  for(l=1;l<=1000;l++)
  {
    for(i=1;i<k && tri[i] <= l;i++)
    {
      for(j=1;j<=3;j++)
      {
        if(res[l-tri[i]][j-1])
        {
          res[l][j]=1;
        }
      }
    }
  }
  for(scanf("%d",&T);T--;)
  {
    int N;
    scanf("%d",&N);
    printf("%d\n",res[N][3]);
  }
}
