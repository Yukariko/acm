int n,s;
main()
{
  int arr[100001];
  scanf("%d%d",&n,&s);
  int i,j,k,sum,min=n+1;
  for(i=0;i<n;scanf("%d",arr+i++));
  for(sum=k=i=0;i<n;i++)
  {
    sum+=arr[i];
    if(sum>=s)
    {
      for(;k<=i;k++)
      {
        sum-=arr[k];
        if(sum<s)
        {
          sum+=arr[k];
          break;
        }
      }
      min=min>i-k?i-k:min;
    }
  }
  printf("%d",min==n+1?0:min+1);
}
