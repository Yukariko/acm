main()
{
	int N,K;
	char ck[100001]={};
	char tmp[11];
	long long i,j,k,res;
	
	scanf("%d%d",&N,&K);
	k = sprintf(tmp,"%d",N);
	for(j=1;k--;j*=10);
	
	long long n = N % K;
	for(res=1;n;res++)
	{	
		if(ck[n])break;
		ck[n]=1;
		n = (n * j + N) % K;
	}
	printf("%d",n?-1:res);
}
