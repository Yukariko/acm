main()
{
  int m,n;
  int u,l,r,d;
  scanf("%d%d",&m,&n);
  scanf("%d%d%d%d ",&u,&l,&r,&d);
  char a[11][11];
  int i,j,k,t;
  for(i=0;i<m;i++)gets(a[i]);
  char map[30][30]={0};
  for(i=0;i<u;i++)
  {
    for(j=0;j<l+r+n;j++)map[i][j]=(i+j)%2?'.':'#';
  }
  for(k=0;k<m;k++)
  {
    for(j=0;j<l;j++)map[i+k][j]=(i+k+j)%2?'.':'#';
    for(t=j;j<t+n;j++)map[i+k][j]=a[k][j-t];
    for(t=0;t<r;t++)map[i+k][j+t]=(i+t+k+j)%2?'.':'#';
  }
  i+=m;
  for(k=0;k<d;k++)
  {
    for(j=0;j<l+r+n;j++)map[i+k][j]=(i+k+j)%2?'.':'#';
  }
  for(i=0;i<u+d+m;i++)puts(map[i]);
}
