#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
main()
{
  int x1,y1,p1,q1;
  int x2,y2,p2,q2;
  for(;~scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&p1,&q1,&x2,&y2,&p2,&q2);)
  {
    x1=MAX(x1,x2);
    y1=MAX(y1,y2);
    p1=MIN(p1,p2);
    q1=MIN(q1,q2);
    if(x1<p1&&y1<q1)puts("a");
    else if(x1==p1&&y1==q1)puts("c");
    else if(x1>p1||y1>q1)puts("d");
    else puts("b");
  }
}
