main()
{
  int n;
  int a=100,b=100;
  int x,y;
  for(scanf("%d",&n);n--;)
  {
    scanf("%d%d",&x,&y);
    if(x<y)a-=y;
    else if (x>y)b-=x;
  }
  printf("%d\n%d",a,b);
}
