int point[4][2];
int d[6];
int dist(int p,int q)
{
  return (point[p][0] - point[q][0]) * (point[p][0] - point[q][0]) \
  + (point[p][1] - point[q][1]) * (point[p][1] - point[q][1]);
}

int cmp(int *p,int *q)
{
  return *p>*q?1:*p<*q?-1:0;
}

main()
{
  int T;
  for(scanf("%d",&T);T--;)
  {
    for(int i=0;i<4;i++)
    {
      scanf("%d%d",&point[i][0],&point[i][1]);
    }
    int pos = 0;
    
    for(int i=0;i<3;i++)
    {
      for(int j=i+1;j<4;j++)
      {
        d[pos++] = dist(i,j);
      }
    }
    qsort(d,6,4,cmp);
    puts(d[0]==d[1]&&d[1]==d[2]&&d[2]==d[3]&&d[4]==d[5]?"1":"0");
  }
}
