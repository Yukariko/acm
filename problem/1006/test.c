#define ISOK(a,b) (a+b <= W)
#define BST(p) (p < NB-1 && B[p] + B[p+1] <= W)
#define AST(p) (p < NA-1 && A[p] + A[p+1] <= W)
#define CST(p) (A[p] + B[p] <= W)
const int INF = 20001;
int N,W;
int A[10001],B[10001];
int dp[3][10001];
int NA,NB;

int min(int a,int b){return a>b?b:a;}

int solve(int aPos,int bPos)
{
	if(aPos == NA && bPos == NB) return 0;
	if(aPos > NA || bPos > NB) return INF;
	if(aPos == NA && NA == N-1)
	{
		if(aPos == bPos) return 1;
		if(aPos - bPos == 1)
		{
			if(BST(bPos)) return 1;
			return 2;
		}
	}
	int *ret = &dp[aPos-bPos][bPos];
	if(*ret != -1) return *ret;
	
	*ret = INF;
	if(aPos == bPos)
	{
		*ret = min(*ret, 1 + solve(aPos+1,bPos));
		if(CST(aPos))
		{
			*ret = min(*ret, 1 + solve(aPos+1,bPos+1)); 
		}
		if(AST(aPos))
		{
			*ret = min(*ret, 1 + solve(aPos+2,bPos));
		}
	}
	else if(aPos - bPos == 1)
	{
		*ret = min(*ret, 1 + solve(aPos+1,bPos));
		*ret = min(*ret, 1 + solve(aPos,bPos+1));
		if(AST(aPos))
		{
			*ret = min(*ret, 2 + solve(aPos+2,bPos+1));
			if(BST(bPos))
			{
				*ret = min(*ret, 2 + solve(aPos+2,bPos+2));
			}
		}
	}
	else
	{
		*ret = min(*ret, 1 + solve(aPos,bPos+1));
		if(BST(bPos))
		{
			*ret = min(*ret, 1 + solve(aPos,bPos+2));
		}
	}
	return *ret;
}

void init()
{
	memset(dp,-1,sizeof(dp));
}

int choragi()
{
	int ret=INF;
	
	init();
	NA=NB=N;
	ret = min(ret, solve(0,0));
	if(N<3)return ret;
	if(ISOK(A[0],A[N-1]))
	{
		init();
		NA = N-1;
		ret = min(ret, 1 + solve(1,0));
		if(ISOK(B[0],B[N-1]))
		{
			init();
			NB = N-1;
			ret = min(ret, 2 + solve(1,1));
		}
	}
	if(ISOK(B[0],B[N-1]))
	{
		init();
		NA = N;
		NB = N-1;
		ret = min(ret, 2 + solve(1,1));
		if(AST(0))
		{
			ret = min(ret, 2 + solve(2,1));
		}
	}
	return ret;
}

main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&N,&W);
		for(int i=0;i<N;i++)
			scanf("%d",&A[i]);
		for(int i=0;i<N;i++)
			scanf("%d",&B[i]);
		printf("%d\n",choragi());
	}
}
