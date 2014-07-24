char a[101][101];
int n;
int x,y,i,j,s;
main()
{
  for(scanf("%d",&n);n--;)
  {
    scanf("%d%d",&x,&y);
    for(i=x;i<x+10;i++)for(j=y;j<y+10;j++)a[i][j]=1;
  }
  for(i=0;i<100;i++)for(j=0;j<100;j++)s+=a[i][j];
  printf("%d",s);
}
