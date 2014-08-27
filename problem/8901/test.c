#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
int ab,bc,ca;
int max;
f(a,b,c,s)
{
  max=max<s?s:max;
  if(a>0&&b>0)f(a-1,b-1,c,s+ab);
  if(a>0&&c>0)f(a-1,b,c-1,s+ca);
  if(b>0&&c>0)f(a,b-1,c-1,s+bc);
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&ab,&bc,&ca);
    max=0;
    f(a,b,c,0);
    printf("%d\n",max);
  }
}
