int max(int p,int q){return p>q?p:q;}
int min(int p,int q){return p>q?q:p;}

int solve(int turn,int A,int B)
{
	if(A % B == 0)
		return turn;
		
	for(long long i=max(((A/B)-1)*B,B);A>=i;i+=B)
		if(turn == solve(!turn,max(A-i,B),min(A-i,B)))
			return turn;

	return !turn;
}

main()
{
	int A,B;
	for(;scanf("%d%d",&A,&B),A;)
		printf("%c wins\n",'A'+solve(0,max(A,B),min(A,B)));
}