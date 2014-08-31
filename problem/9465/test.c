#define MAX(a,b) (a>b?a:b)
main()
{
  int t;
  int a[100001];
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    int i,j;
    int x,y;
    int tx,ty;
    for(i=0;i<n;i++)scanf("%d",a+i);
    x=a[0];
    scanf("%d",&y);
    for(i=1;i<n;i++)
    {
      scanf("%d",&j);
      tx=MAX(x,y+a[i]);
      ty=MAX(y,j+x);
      x=tx;
      y=ty;
    }
    printf("%d\n",MAX(x,y));
  }
}
