#define MIN(a,b) ((a)>(b)?(b):(a))
main()
{
  int w,h;
  scanf("%d%d",&w,&h);
  int p,q,t;
  scanf("%d%d%d",&p,&q,&t);
  int x=1,y=1,k;
  for(;t;)
  {
    k=MIN((x==1?w-p:p),(y==1?h-q:q));
    k=MIN(k,t);
    t-=k;
    p+=k*x;
    q+=k*y;
    if(p==w)x=-1;
    else if(p==0)x=1;
    if(q==h)y=-1;
    else if(q==0)y=1;
  }
  printf("%d %d",p,q);
}
