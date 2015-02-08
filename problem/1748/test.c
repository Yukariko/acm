long long digitCount(long long n,int i)
{
  long long res,j,k,t;
  res=0;
  for(t=0,j=1;j<=n;j*=10,t++)
  {
    k=(n/j)%10;
    if(i==0)
    {
      if(!k)
      {
        res-=j-1;
        res+=n%j;
      }
    }
    else if(i<k)res+=j;
    else if(i==k)res+=n%j+1;
    res+=k*t*(j/10);
  }
  return res;
}
main()
{
	int N;
	scanf("%d",&N);
	int ret=0;
	for(int i=0;i<10;i++)ret+=digitCount(N,i);
	printf("%d",ret);
}
