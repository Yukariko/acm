main()
{
  int n,k,y,m;
  y=m=0;
  for(scanf("%d",&n);n--;)
  {
    scanf("%d",&k);
    y+=(k/30+1)*10;
    m+=(k/60+1)*15;
  }
  if(y<m)printf("Y %d",y);
  else if (y==m)printf("Y M %d",y);
  else printf("M %d",m);
}
