char P[101];
int K;

int isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int isDiv(int n)
{
	int mod = 0;
	for(int i=0;P[i];i++)
	{
		mod *= 10;
		mod += P[i] - '0';
		mod %= n;
	}
	return !mod;
}

main()
{
	scanf("%s%d",P,&K);
	
	for(int i=2;i<=K;i++)
	{
		if(isPrime(i) && isDiv(i))
		{
			printf("BAD %d",i);
			return 0;
		}
	}
	puts("GOOD");
}