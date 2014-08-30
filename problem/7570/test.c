int a[1000001];
int b[1000002];
main()
{
  int n;
  int max=0;
  scanf("%d",&n);
  int i,j,k;
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    b[a[i]]=i;
  }
  b[n+1]=0;
  int s;
  for(i=0;i<n;i++)
  {
    s=b[a[i]];
    for(j=a[i]+1;b[j]>s;j++)s=b[j];
    max=max<j-a[i]?j-a[i]:max;
  }
  printf("%d",n-max);
}
