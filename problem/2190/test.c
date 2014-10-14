main()
{
  int N;
  long long A, B;
  long long point[101][2];
  int i,j,k;
  scanf("%d%lld%lld",&N,&A,&B);
  for(i=0;i<N;i++)
  {
    scanf("%lld%lld",&point[i][0],&point[i][1]);
  }
  long long sx,ex,sy,ey;
  int s,max=0;
  for(i=0;i<N;i++)
  {
    sx=point[i][1];
    ex=point[i][1]+B;
    sy=point[i][0];
    ey=point[i][0]+A;
    for(j=0;j<N;j++)
    {
      if(point[i][0]>point[j][0])
      {
        sy=point[j][0];
        ey=point[j][0]+A;
      }
      s=0;
      for(k=0;k<N;k++)
      {
        if(sy<=point[k][0]&&point[k][0]<=ey&&sx<=point[k][1]&&point[k][1]<=ex)
        {
          s++;
        }
      }
      max=max<s?s:max;
    }
  }
  printf("%d",max);
}
