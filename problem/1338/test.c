long long max(long long a,long long b){return a>b?a:b;}
main()
{
	long long a,b,x,y,k;
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	long long ret = 1LL<<51;
	if(b<a)
	{
		long long t = a;
		a = b;
		b = t;
	}
	if(x <= y)return puts("Unknwon Number"),0;
	if(a >= 0)
	{
		if(a <= a / x * x + y)
			k = a / x * x + y;
		else
			k = (a / x + 1) * x + y;
	}
	else
	{
		if(a <= (a / x - 1) * x + y)
			k = (a / x - 1) * x + y;
		else
			k = (a / x) * x + y;
	}
    
	if(a <= k && k <= b)
		ret = k;
	if(ret == 1LL<<51 || ret + x <= b)puts("Unknwon Number");
	else printf("%lld",ret);
}
