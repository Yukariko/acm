int a[2000001];
main()
{
  int i,n,s=0;
  for(scanf("%d",&n);i<=n;i++)a[i]=i;
  for(i=1;a[i];i+=2)
  {
    s=a[i];
    a[++n]=a[i+1];
  }
  printf("%d",s);
}

