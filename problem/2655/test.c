typedef struct stone{int no,s,h,w;}STONE;
cmp(STONE *a,STONE *b)
{
  return a->s>b->s?-1:a->s<b->s?1:0;
}
STONE stone[101];
int tower[101];
int cnt;
int n;
int temp[101];
int max;
int dp[101];
f(p,h,c)
{
  int i;
  if(h<dp[p])return;
  dp[p]=dp[p]<h?h:dp[p];
  if(max<h)
  {
    max=h;
    cnt=c;
    for(i=0;i<c;i++)tower[i]=temp[i];
  }
  for(i=p+1;i<=n;i++)
  {
    if(stone[p].w>stone[i].w)
    {
      temp[c]=stone[i].no;
      f(i,h+stone[i].h,c+1);
    }
  }
}
main()
{
  scanf("%d",&n);
  int i;
  for(i=1;i<=n;i++)
  {
    stone[i].no=i;
    scanf("%d%d%d",&stone[i].s,&stone[i].h,&stone[i].w);
  }
  qsort(&stone[1],n,sizeof(STONE),cmp);
  
  for(i=1;i<=n;i++)
  {
    temp[0]=stone[i].no;
  	f(i,stone[i].h,1);
  }
  
  printf("%d\n",cnt);
  for(;cnt--;)printf("%d\n",tower[cnt]);
}
