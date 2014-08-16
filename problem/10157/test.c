main()
{
  int c,r,k;
  scanf("%d%d%d",&c,&r,&k);
  if(c*r<k)puts("0");
  else
  {
    int x,y,i,tx=0,ty=1;
    int g=r-1,t,count=0;
    for(x=y=i=1;i<k;i++)
    {
      x+=tx;
      y+=ty;
      if(i==g)
      {
        g=i+(tx?r:c)-1-count/2;
        t=tx;
        tx=ty;
        ty=-t;
        count++;
      }
    }
    printf("%d %d",x,y);
  }
}
