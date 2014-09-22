typedef struct numGame{int x,s,b;}GAME;
GAME g[101];
int n;
f(p)
{
  int a[3],b[3];
  a[0]=p/100;
  a[1]=p/10%10;
  a[2]=p%10;
  int i,j,k,strike,ball;
  for(i=0;i<n;i++)
  {
    b[0]=g[i].x/100;
    b[1]=g[i].x/10%10;
    b[2]=g[i].x%10;
    strike=ball=0;
    for(j=0;j<3;j++)
    {
      for(k=0;k<3;k++)
      {
        if(j==k&&a[j]==b[k])strike++;
        else if(j!=k&&a[j]==b[k])ball++;
      }
    }
    if(strike!=g[i].s||ball!=g[i].b)return 0;
  }
  return 1;
}
int a[10];
int cnt;
make_num(p)
{
  int i;
  if(p>100)
  {
    if(f(p))cnt++;
    return;
  }
  for(i=1;i<=9;i++)
  {
    if(a[i]==0)
    {
      a[i]=1;
      make_num(p*10+i);
      a[i]=0;
    }
  }
}
main()
{
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d%d%d",&g[i].x,&g[i].s,&g[i].b);
  }
  make_num(0);
  printf("%d",cnt);
}
