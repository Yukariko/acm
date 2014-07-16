a[2501];
main(i,n)
{
  for(scanf("%d",&n);i<=n;i++)a[i]=i;
  for(i=1;a[i];i+=2)
  {
    printf("%d ",a[i]);
    a[++n]=a[i+1];
  }
}

