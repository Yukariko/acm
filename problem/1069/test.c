int x,y,d,t,i,j;
double s[2002],k;
double absd(double a){return a>0?a:-a;}
main()
{
  for(;~scanf("%d%d%d%d",&x,&y,&d,&t);)
  {
    j=0;
    k=sqrt(x*x+y*y);
    s[0]=t+absd(k-d);
    s[1]=k;
    for(i=2;i<2001;i++)
    {
      if(k>i*d)s[i]=i*t+k-i*d;
      else s[i]=i*t;
    }
    k=2000;
    for(i=0;i<2000;i++)k=s[i]<k?s[i]:k;
    printf("%.11lf\n",k);
  }
}
