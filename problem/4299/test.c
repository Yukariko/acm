main()
{
  int a,b,x,y;
  scanf("%d%d",&a,&b);
  x=(a+b)/2;
  y=(a-b)/2;
  if(a<b||x+y!=a||x-y!=b)puts("-1");
  else printf("%d %d",x,y);
}
