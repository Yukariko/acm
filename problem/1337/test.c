cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n;
  scanf("%d",&n);
  int a[10001];
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  qsort(a,n,4,cmp);
  int max=0,s=0;
  for(i=0;i<n-1;i++)
  {
    if(a[i]+1==a[i+1])s++;
    else s=0;
    max=max<s?s:max;
  }
  int min=5-max-1;
  
  printf("%d",max>=4?0:min);
}
