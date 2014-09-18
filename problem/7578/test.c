int a[1000001];
int b[500001];
main()
{
  int n;
  scanf("%d",&n);
  int i,k;
  for(i=1;i<=n;i++)
  {
    scanf("%d",&k);
    a[k]=i;
  }
  int s=0;
  int max=0;
  for(i=1;i<=n;i++)
  {
    scanf("%d",&k);
    max=max<a[k]?a[k]:max;
    s+=a[k]>i?a[k]-i:a[k]==i&&i<max?1:0;
  }
  printf("%d",s);
}
