#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef struct FISH{int x,y;}FISH;
FISH fish[101];
main()
{
  int N,L,M;
  scanf("%d%d%d",&N,&L,&M);
  int x,y;
  int i;
  for(i=0;i<M;i++)
  {
    scanf("%d%d",&y,&x);
    fish[i].x=x;
    fish[i].y=y;
  }
  int p,q,r,s;
  int j,k,max=0;
  for(i=0;i<M;i++)
  {
    for(p=1;2*p+2<=L;p++)
    {
      q=(L-2*p)/2;
      for(j=fish[i].y-q;j<=fish[i].y+q;j++)
      {
        if(fish[i].x+p<=N&&j>=0&&j+q<=N)
        {
          s=0;
          for(k=0;k<M;k++)
          {
            if(fish[k].x>=fish[i].x&&fish[k].x<=fish[i].x+p&&fish[k].y>=j&&fish[k].y<=j+q)s++;
          }
          max=max<s?s:max;
        }
      }
    }
  }
  printf("%d",max);
}
