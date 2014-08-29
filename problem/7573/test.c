#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
char map[10022][10022]={0};
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
    map[y][x]=1;
    fish[i].x=x;
    fish[i].y=y;
  }
  int p,q,r,s;
  int j,k,max=0;
  //puts("---");
  for(i=0;i<M;i++)
  {
    for(p=1;2*p+2<=L;p++)
    {
      q=(L-2*p)/2;
    //  printf("%d %d\n",p,q);
      if(fish[i].x+p<=N&&fish[i].y+q<=N)
      {
        s=0;
        j=fish[i].x+p;
        k=fish[i].y+q;
        for(x=fish[i].x;x<=j;x++)
        {
          for(y=fish[i].y;y<=k;y++)if(map[y][x])s++;
        }
        max=max<s?s:max;
      }
      else if(fish[i].x+p<=N&&N-q>=1)
      {
        s=0;
        j=fish[i].x+p;
        k=N;
        for(x=fish[i].x;x<=j;x++)
        {
          for(y=N-q;y<=k;y++)if(map[y][x])s++;
        }
        max=max<s?s:max;
      }
      else if(fish[i].y+q<=N&&N-p>=1)
      {
        s=0;
        j=N;
        k=fish[i].y+q;
        for(x=N-p;x<=j;x++)
        {
          for(y=fish[i].y;y<=k;y++)if(map[y][x])s++;
        }
        max=max<s?s:max;        
      }
      else if(N-p>=1&&N-q>=1)
      {
        s=0;
        j=N;
        k=N;
        for(x=N-p;x<=j;x++)
        {
          for(y=N-q;y<=k;y++)if(map[y][x])s++;
        }
        max=max<s?s:max; 
      }
    }
  }
  printf("%d",max);
}
