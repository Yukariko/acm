main()
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a+b+c!=180)puts("Error");
  else if(a==60&&b==c)puts("Equilateral");
  else if(a!=b&&b!=c&&c!=a)puts("Scalene");
  else puts("Isosceles");
}
