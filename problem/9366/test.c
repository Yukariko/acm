main()
{
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("Case #%d: ",i);
    if(a+b <= c || a+c <= b || b+c <= a)puts("invalid!");
    else if(a==b && b==c)puts("equilateral");
    else if(a!=b&&b!=c&&c!=a)puts("scalene");
    else puts("isosceles");
  }
}
