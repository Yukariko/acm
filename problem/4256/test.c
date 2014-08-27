int pre[1001];
int in[1001];
f(i,j,k)
{
  int t=i;
  for(;i<j;i++)
  {
    if(in[i]==pre[k])
    {
      f(t,i,k+1);
      f(i+1,j,k+i-t+1);
      printf("%d ",pre[k]);
      return;
    }
  }
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n;scanf("%d",&n);
    for(int i=0;i<n;scanf("%d",pre+i++));
    for(int i=0;i<n;scanf("%d",in+i++));
    f(0,n,0);
    puts("");
  }
}
