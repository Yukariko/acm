char graph[101][101];
int x0,y0,x1,y1,yn,s;
main()
{
  for(;~scanf("%d%d%d%d",&x0,&y0,&x1,&y1);)for(;x0<x1;x0++)for(yn=y0;yn<y1;yn++)graph[yn][x0]=1;
  for(x0=0;x0<100;x0++)for(y0=0;y0<100;y0++)s+=graph[y0][x0];
  printf("%d",s);
}
