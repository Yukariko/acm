int b[500001];
main()
{
  int n;
  int a[500001];
  scanf("%d",&n);
  int i,j;
  scanf("%d",a);
  int max=a[0];
  printf("0 ");
  for(i=1;i<n;i++)
  {
    scanf("%d",a+i);
    if(max<a[i])
    {
      printf("0 ");
      max=a[i];
    }
    else
    {
      for(j=i-1;a[i]>a[j];j=b[j]);
      b[i]=j;
      printf("%d ",j+1);
    }
  }
}
