cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
int a[500001];
int dp[500001];
main()
{

  int i,n,t,s=0,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    for(j=i;j;j--)if(a[i]<a[j-1])s++;
  }
  printf("%d\n",s);
}
