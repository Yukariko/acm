main()
{
  int n,s,p;
  scanf("%d%d%d",&n,&s,&p);
  int a[51];
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  if(n==p&&a[p-1]>=s)return puts("-1"),0;
  int rank=1,count=1;
  for(i=0;i<n;i++)
  {
    if(n==0)return puts("1"),0;
    if(a[i]<=s)break;
    if(i<n-1&&a[i]==a[i+1])count++;
    else{rank+=count;count=1;}
  }
  printf("%d",rank);
}
