cmp(int *a,int *b){return *a-*b;}
main()
{
  int n;
  scanf("%d",&n);
  int a[20001];
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  qsort(a,n,4,cmp);
  printf("%d",a[(n+1)/2-1]);
}
