main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  int ax,ay;
  int bx,by;
  a-=1;b-=1;
  ax=a/4;
  ay=a%4;
  bx=b/4;
  by=b%4;
  printf("%d",abs(ax-bx)+abs(ay-by));
}
