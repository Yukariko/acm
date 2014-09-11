char a[11];
f(p)
{
  int i,s1,s2;
  s1=s2=1;
  for(i=0;i<p;i++)s1*=a[i]-'0';
  for(i=p;a[i];i++)s2*=a[i]-'0';
  return s1==s2;
}
main()
{
  gets(a);
  int i;
  for(i=1;a[i];i++)
  {
    if(f(i))return puts("YES"),0;
  }
  puts("NO");
}
