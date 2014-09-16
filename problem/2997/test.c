f(a,b){return b?f(b,a%b):a;}
cmp(int *a,int *b){return *a-*b;}
main()
{
  int a[4];
  scanf("%d%d%d",a,a+1,a+2);
  qsort(a,3,4,cmp);
  if(a[1]-a[0]==a[2]-a[1])return printf("%d",a[2]+a[2]-a[1]),0;
  if(a[1]-a[0]>a[2]-a[1])printf("%d",a[0]+f(a[1]-a[0],a[2]-a[1]));
  if(a[1]-a[0]<a[2]-a[1])printf("%d",a[1]+f(a[1]-a[0],a[2]-a[1]));
}
