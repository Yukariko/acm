char map[12][12],temp[12][12];
int i,j,count,p,q;
main(r,c)
{
  scanf("%d%d\n",&r,&c);
  for(i=1;i<=r;i++)gets(&map[i][1]);
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
      if(map[i][j]=='X')
      {
        count=0;
        count+=map[i-1][j]-'X'?1:0;count+=map[i+1][j]-'X'?1:0;
        count+=map[i][j-1]-'X'?1:0;count+=map[i][j+1]-'X'?1:0;
        if(count>=3)temp[i][j]='.';
        else temp[i][j]='X';
      }
      else temp[i][j]='.'; 
    }
  }
  for(i=1;i<=r;i++){count=0;for(j=1;j<=c;j++)if(temp[i][j]=='X'){count=1;break;}if(count)break;}p=i;
  for(i=r;i>=0;i--){count=0;for(j=1;j<=c;j++)if(temp[i][j]=='X'){count=1;break;}if(count)break;}r=i;
  for(i=1;i<=c;i++){count=0;for(j=1;j<=r;j++)if(temp[j][i]=='X'){count=1;break;}if(count)break;}q=i;
  for(i=c;i>=0;i--){count=0;for(j=1;j<=r;j++)if(temp[j][i]=='X'){count=1;break;}if(count)break;}c=i;
  //printf("%d %d\n%d %d",p,r,q,c);
  for(i=p;i<=r;puts(""),i++)for(j=q;j<=c;j++)printf("%c",temp[i][j]);
}
