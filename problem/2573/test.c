int N,M;
char map[301][301];
char visit[301][301];

void dfs(int y,int x)
{
  if(visit[y][x]) return;
  if(!map[y][x]) return;
  visit[y][x] = 1;
  dfs(y+1,x);
  dfs(y-1,x);
  dfs(y,x+1);
  dfs(y,x-1);
}

main()
{
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
      scanf("%d",&map[i][j]);
    }
  }
  int ret=0;
  while(1)
  {
    int ck=0;
    char temp[301][301];
    memcpy(temp,map,sizeof(map));
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(map[i][j])
        {
          ck=1;
          temp[i][j] = map[i][j] - !map[i-1][j] - !map[i+1][j] - !map[i][j-1] - !map[i][j+1]; 
          if(temp[i][j]<0)temp[i][j]=0;
        }
      }
    }
    if(ck == 0){ret=0;break;}
    ret++;
    memcpy(map,temp,sizeof(temp));
    memset(visit,0,sizeof(visit));
    int piece=0;
    for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
      {
        if(!visit[i][j] && map[i][j])
        {
          piece++;
          dfs(i,j); 
        }
      }
    }
    if(piece >= 2)break;
  }
  
  printf("%d",ret);
}