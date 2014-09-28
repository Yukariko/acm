cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int a[1000001];
main()
{
  int n;
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",a+i);
  qsort(a,n,4,cmp);
  for(i=n-1;i>=0;i--)
  {
    if(a[i]<a[i-1]+a[i-2])break;
  }
  printf("%d",i<0?-1:a[i]+a[i-1]+a[i-2]);
}
