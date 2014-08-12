int n,k;
int a[101];
cmp(int *p,int *q)
{
  return *p>*q?-1:*p<*q?1:0;
}
main()
{
  int i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    int max,min,gap=0;
    printf("%s %d\n","Class",i);
    scanf("%d",&k);for(j=0;j<k;scanf("%d",a+j++));
    qsort(a,k,4,cmp);
    max=a[0];min=a[k-1];
    for(j=0;j<k-1;j++)gap=gap<a[j]-a[j+1]?a[j]-a[j+1]:gap;
    printf("Max %d, Min %d, Largest gap %d\n",max,min,gap);
  }
}
