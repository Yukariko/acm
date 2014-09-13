cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int t;
  int i;
  int a[3];
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  {
    scanf("%d%d%d",a,a+1,a+2);
    qsort(a,3,4,cmp);
    printf("Scenario #%d:\n%s\n\n",i,a[0]*a[0]+a[1]*a[1]==a[2]*a[2]?"yes":"no");
  }
}
