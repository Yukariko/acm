char map[21][21];
int r,c;
int max;
char a[99];
f(int i,int j,int k)
{
  if(i<0||j<0||i>=r||j>=c||a[map[i][j]])return;
  int p;
  a[map[i][j]]=1;
  f(i-1,j,k+1);f(i+1,j,k+1);f(i,j-1,k+1);f(i,j+1,k+1);
  a[map[i][j]]=0;
  max=max<k?k:max;
}
main()
{
  scanf("%d%d ",&r,&c);
  int i;
  for(i=0;i<r;i++)gets(map[i]);
  f(0,0,1);
  printf("%d",max);
}
