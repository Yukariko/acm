int n;
double s=1,E,W,N,S;
char map[30][30];
f(int c,int x,int y,double p)
{
  if(map[x][y]){s-=p;return;}
  if(c==0)return;
  map[x][y]=1;
  f(c-1,x-1,y,p*E);
  f(c-1,x+1,y,p*W);
  f(c-1,x,y-1,p*N);
  f(c-1,x,y+1,p*S);
  map[x][y]=0;
}
main()
{
  scanf("%d%lf%lf%lf%lf",&n,&E,&W,&N,&S);
  E/=100.0;W/=100.0;N/=100.0;S/=100.0;
  f(n,15,15,1.0);
  printf("%.10f",s);
}
