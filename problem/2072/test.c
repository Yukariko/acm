int omok[21][21];
int n;
f(x,y,t)
{
  int i,c;
  for(c=i=0;omok[x+i][y]==t;i++)c++;for(i=1;omok[x-i][y]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x][y+i]==t;i++)c++;for(i=1;omok[x][y-i]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x+i][y+i]==t;i++)c++;for(i=1;omok[x-i][y-i]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x-i][y+i]==t;i++)c++;for(i=1;omok[x+i][y-i]==t;i++)c++;
  if(c==5)return 1;
  
  return 0;
}
main(i)
{
  int x,y;
  for(scanf("%d",&n);i<=n;i++)
  {
    scanf("%d%d",&x,&y);
    omok[x][y]=1+i%2;
    if(f(x,y,1+i%2)){printf("%d",i);return;}
  }
  puts("-1");
}
