main()
{
  int N,M,T,K;
  int point[101][2];
  int i,j,k;
  scanf("%d%d%d%d",&N,&M,&T,&K);
  for(i=0;i<T;i++)
  {
    scanf("%d%d",&point[i][0],&point[i][1]);
  }
  int sx,ex,sy,ey;
  int s,max=0,rx,ry;
  for(i=0;i<T;i++)
  {
    sx=point[i][1];
    ex=point[i][1]+K;
    if(ex>M)
    {
      sx-=ex-M;
      ex=M;
    }
    for(j=0;j<T;j++)
    {
      sy=point[j][0];
      ey=point[j][0]+K;
      if(ey>N)
      {
        sy-=ey-N;
        ey=N;
      }
      s=0;
      for(k=0;k<T;k++)
      {
        if(sy<=point[k][0]&&point[k][0]<=ey&&sx<=point[k][1]&&point[k][1]<=ex)
        {
          s++;
        }
      }
      if(max<s)
      {
        max=s;
        rx=ex;
        ry=sy;
      }
    }
  }
  printf("%d %d\n%d",ry,rx,max);
}
