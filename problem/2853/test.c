main()
{
  int n;
  int a[5001];
  int i,j,s=0;
  scanf("%d",&n);
  scanf("%d",a);
  for(i=1;i<n;i++)
  {
    scanf("%d",a+i);
    for(j=1;j<i;j++)
    {
      if((a[i]-1)%(a[j]-1)==0)break;
    }
    if(j==i)s++;
  }
  printf("%d",s);
}
