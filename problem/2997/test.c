cmp(int *a,int *b){return *a-*b;}
main()
{
  int a[4];
  int x,y;
  scanf("%d%d%d",a,a+1,a+2);
  qsort(a,3,4,cmp);
  x=a[1]-a[0];y=a[2]-a[1];
  printf("%d",x==y?a[2]+x:x>y?a[0]+y:a[1]+x);
}
