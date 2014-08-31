#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
main()
{
  int t;
  char a[501];
  for(scanf("%d ",&t);t--;)
  {
    gets(a);
    int minX=0,minY=0,maxX=0,maxY=0;
    int x=0,y=0,tx=0,ty=1,t;
    int i;
    for(i=0;a[i];i++)
    {
      if(a[i]=='F'){x+=tx;y+=ty;}
      else if(a[i]=='B'){x-=tx;y-=ty;}
      else if(a[i]=='L'){t=tx;tx=-ty;ty=t;}
      else if(a[i]=='R'){t=tx;tx=ty;ty=-t;}
      minX=MIN(minX,x);
      minY=MIN(minY,y);
      maxX=MAX(maxX,x);
      maxY=MAX(maxY,y);
    }
    printf("%d\n",(maxX-minX)*(maxY-minY));
  }
}
