#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
main()
{
  int X1,Y1,X2,Y2;
  long long res=0;
  scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
  for(Y1++;Y1<=Y2;Y1++)
  {
    if(Y1 > X1 && (Y1 & 1) == 0)
    {
      res+=MIN(Y1,X2)-X1;
    }
    res+=(X2-MIN((MAX(Y1,X1)>>1)<<1,X2))>>1;
  }
  printf("%lld",res);
}
