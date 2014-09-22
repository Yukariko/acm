digit(n)
{
  int s;
  for(s=0;n;n/=10)s+=n%10;
  return s;
}
hex(n)
{
  int s;
  for(s=0;n;n/=16)s+=n%16;
  return s;
}
due(n)
{
  int s;
  for(s=0;n;n/=12)s+=n%12;
  return s;
}
main()
{
  int i,d,h,r;
  for(i=1000;i<10000;i++)
  {
    d=digit(i);
    h=hex(i);
    r=due(i);
    if(d==h&&h==r)printf("%d\n",i);
  }
}
