#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
main()
{
  int t;
  for(scanf("%d",&t);t;t--)
  {
    
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    int i,j;
    int s=0;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    s=(x2-x1)*(y2-y1);
    s-=(MIN(x2,x4)-MAX(x1,x3))*(MIN(y2,y4)-MAX(y1,y3));
    printf("%d\n",s);
  }
}
