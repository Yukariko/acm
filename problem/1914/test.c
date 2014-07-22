f(n,a,b)
{
  int t=6-a-b;
  if(n==1)
  {
    printf("%d %d\n",a,b);
  }
  else
  {
    f(n-1,a,t);
    printf("%d %d\n",a,b);
    f(n-1,t,b);
  }
}
char a[101];
int i,s,k,p;
main(n)
{
  a[100]='1';
  for(scanf("%d",&n);k<n;k++)
  {
    s=0;
    for(i=100;a[i];i--)
    {
      p=s+(a[i]-'0')*2;
      s=p/10;
      a[i]=p%10+'0';
    }
    if(s)a[i--]='1';
  }
  a[100]-=1;
  puts(a+i+1);
  if(n<21)f(n,1,3);
}
