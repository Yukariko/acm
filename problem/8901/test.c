#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int a,b,c;
    int ab,bc,ca;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d%d%d",&ab,&bc,&ca);
    int i,j;
    int max=0;
    int minAB,minBC;
    minAB=MIN(a,b);
    for(i=0;i<=minAB;i++)
    {
      minBC=MIN(b-i,c);
      for(j=0;j<=minBC;j++)
      {
        max=MAX(ab*i+bc*j+ca*MIN(a-i,c-j),max);
      }
    }
    printf("%d\n",max);
  }
}
