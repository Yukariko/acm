a[101],b[101];i;j;
main(n,k)
{
  for(scanf("%d%d",&n,&k);~scanf("%d",a+i++););
  for(i=0;i<=n-k;i++)for(j=i;j<i+k;j++)b[i]+=a[j];
  j=-1<<9;for(i=0;i<=n-k;i++)j=j<b[i]?b[i]:j;
  printf("%d",j);
}
