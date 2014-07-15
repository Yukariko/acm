int friend[501][501],list[501];
int n,m,x,y,s;
main(i,j)
{
  for(scanf("%d%d",&n,&m);~scanf("%d%d",&x,&y);)friend[x][y]=1;
  for(i=2;i<=n;i++)
  {
     if(friend[1][i]||friend[i][1])
     {
       for(j=1;j<=n;j++)
       {
         if(friend[i][j]||friend[j][i])
          list[i]=list[j]=1;
       }
     }
  }
  for(i=2;i<=n;i++)s+=list[i];
  printf("%d",s);
}
 
