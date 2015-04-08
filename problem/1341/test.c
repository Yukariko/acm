main()
{
	long long A,B;
	char res[61];

	scanf("%lld%lld",&A,&B);
	if(A == 0)
		return puts("-"),0;
	if(A == 1 && B == 1)
		return puts("*"),0;
	
	int ck = 0;
	int len = 0;
	long long k = 4;
	for(int i=2;i<=60;i++)
	{
		if(k-1 >= B && (k-1) % B == 0)
		{
			ck = 1;
			len = i;
			A *= (k-1) / B;
			B = (k-1);
			break;
		}
		k<<=1;
	}

	if(!ck) return puts("-1"),0;

	int aLen = 0;
	for(long long i=1;i<=A;i<<=1)aLen++;

	for(int i=0;i<len-aLen;i++)
		putchar('-');

	int count = 0;
	for(;A;)
	{
		if(A & 1)
			res[count++]='*';
		else
			res[count++]='-';
		A>>=1;
	}

	for(int i=count-1;i>=0;i--)
		putchar(res[i]);
}