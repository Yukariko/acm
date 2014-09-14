#define MIN(a,b) ((a)>(b)?(b):(a))
main()
{
  int w,h;
  scanf("%d%d",&w,&h);
  int p,q,t;
  scanf("%d%d%d",&p,&q,&t);
  int x=1,y=1,k;
  int sx,sy,st,c;
  for(c=0;t;)
  {
    k=MIN((x==1?w-p:p),(y==1?h-q:q));
    k=MIN(k,t);
    t-=k;
    p+=k*x;
    q+=k*y;
    if(x==1&&p==w)x=-1;
    else if(x==-1&&p==0)x=1;
    if(y==1&&q==h)y=-1;
    else if(y==-1&&q==0)y=1;
    if(c==0){sx=p;sy=q;st=t;c=1;}
    else if(sx==p&&sy==q&&c==1)
    {
      t%=t-st;
      c=2;
    }
    printf("%d %d %d\n",p,q,t);
  }
  printf("%d %d",p,q);
}
