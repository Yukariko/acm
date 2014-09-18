#define MAX(a,b) (a>b?a:b)
main()
{
  long long x,y,w,s;
  scanf("%lld%lld%lld%lld",&x,&y,&w,&s);
  if(w*2<=s)return printf("%lld",x*w+y*w),0;
  if(s<=w)return printf("%lld",(x+y)%2?w+(MAX(x,y)-1)*s:MAX(x,y)*s),0;
  printf("%lld",x>y?(x-y)*w+y*s:(y-x)*w+x*s);
}
