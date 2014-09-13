cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
f(n,p,q)
{
  int i,j;
  i=n-p-1;
  j=q-n-1;
  return i+j+i*j;
}
main()
{
  int l,n;
  int i,j,k;
  scanf("%d",&l);
  int a[51];
  for(i=0;i<l;i++)
  {
    scanf("%d",a+i);
  }
  qsort(a,l,4,cmp);
  scanf("%d",&n);
  for(i=0;i<l-1;i++)
  {
    if(a[i]==n||a[i+1]==n)return puts("0"),0;
    if(a[i]<n&&n<a[i+1])break;
  }
  printf("%d",i==l-1?f(n,0,a[0]):f(n,a[i],a[i+1]));
}
