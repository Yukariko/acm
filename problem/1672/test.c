#define numlize(p) (p=='A'?0:p=='G'?1:p=='C'?2:3)

char decrypt(char p,char q)
{
	p = numlize(p);
	q = numlize(q); 
	return "ACAGCGTAATCGGAGT"[p*4+q];
}

main()
{
	int N;
	scanf("%d ",&N);
	char a[N+1];
	gets(a);

	for(int i=N-2;i>=0;i--)
	{
		a[i] = decrypt(a[i],a[i+1]);
	}
	printf("%c",a[0]);
}