#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
main()
{
  int n;
  scanf("%d",&n);
  long long A,B,C,D,E,F;
  scanf("%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&E,&F);
  long long min1,min2,min3;
  long long max;
  min1=MIN(A,MIN(B,MIN(C,MIN(D,MIN(E,F)))));
  max=MAX(A,MAX(B,MAX(C,MAX(D,MAX(E,F)))));
  if(n==1)return printf("%lld",A+B+C+D+E+F-max),0;
  min2=A+D;
  min2=MIN(min2,A+C);
  min2=MIN(min2,A+E);
  min2=MIN(min2,A+B);
  min2=MIN(min2,B+F);
  min2=MIN(min2,B+D);
  min2=MIN(min2,B+C);
  min2=MIN(min2,C+E);
  min2=MIN(min2,C+F);
  min2=MIN(min2,D+E);
  min2=MIN(min2,D+F);
  min2=MIN(min2,E+F);
  min3=A+D+E;
  min3=MIN(min3,A+E+C);
  min3=MIN(min3,A+C+B);
  min3=MIN(min3,A+D+B);
  min3=MIN(min3,B+D+F);
  min3=MIN(min3,B+C+F);
  min3=MIN(min3,C+E+F);
  min3=MIN(min3,D+E+F);
  printf("%lld",min1*(n-2)*((n-2)*5+4)+min2*((n-2)*4+(n-1)*4)+min3*4);
}
