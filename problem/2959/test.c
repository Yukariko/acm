cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int a[4];
  int i;
  for(i=0;i<4;i++)scanf("%d",a+i);
  qsort(a,4,4,cmp);
  printf("%d",a[0]*a[2]);
}
