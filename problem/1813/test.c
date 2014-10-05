main()
{
  int n;
  int a[100001]={};
  int i,max=0;
  for(scanf("%d",&n);n--;)
  {
    scanf("%d",&i);
    a[i]++;
    max=max<i?i:max;
  }
  for(i=max;i;i--)
  {
    if(a[i]==i)return printf("%d",i),0;
  }
  puts(a[0]?"-1":"0");
}
