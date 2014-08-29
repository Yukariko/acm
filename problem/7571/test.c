typedef struct point{int x,y;}point;
int x[100001];
int y[100001];
int dp[100001];
cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j;
  int px,py;
  for(i=0;i<m;i++)
  {
    scanf("%d%d",&x[i],&y[i]);
  }
  qsort(x,m,4,cmp);
  qsort(y,m,4,cmp);
  px=x[m/2];
  py=y[m/2];
  int t;
  int s;
  s=0;
  for(i=0;i<m;i++)
  {
    t=abs(px-x[i])+abs(py-y[i]);
    s+=t;
  }
  printf("%d",s);
}
