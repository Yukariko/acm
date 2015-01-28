int N,M;
int A[501],B[501];
short warpA[501][501],warpB[501][501];
int temp[501],ans[501];
short dp[501][501];
int rMax;
int max(int a,int b){return a>b?a:b;}

int solve(int aPos, int bPos, long long last, int rPos)
{
	if(rMax < rPos)
	{
		rMax = rPos;
		for(int i=0;i<rMax;i++)ans[i]=temp[i];
	}
	if(aPos == N && bPos == M) return 0;

	if(dp[aPos][bPos] >= rPos) return dp[aPos][bPos];
	dp[aPos][bPos] = rPos;

	for(int i=aPos;i<N;i++)
	{
		if(last < A[i])
		{
			if(warpA[i][bPos] == -1)
			{
				int bFind;
				for(bFind=bPos;bFind<M;bFind++)
				{
					if(A[i] == B[bFind])
					{
						warpA[i][bPos] = bFind;
						break;
					}
				}
			}
			if(warpA[i][bPos] != -1)
			{
				temp[rPos] = A[i];
				solve(i+1, warpA[i][bPos]+1, A[i], rPos + 1);
			}
		}
	}
	for(int i=bPos;i<M;i++)
	{
		if(last < B[i])
		{
			if(warpB[i][aPos] == -1)
			{
				int aFind;
				for(aFind=aPos;aFind<N;aFind++)
				{
					if(B[i] == A[aFind])
					{
						warpB[i][aPos] = aFind;
						break;
					}
				}
			}
			if(warpB[i][aPos] != -1)
			{
				temp[rPos] = B[i];
				solve(warpB[i][aPos]+1, i+1, B[i], rPos + 1);
			}
		}
	}
}

main()
{
	scanf("%d",&N);
	for(int i=0;i<N;scanf("%d",A+i++));
	scanf("%d",&M);
	for(int i=0;i<M;scanf("%d",B+i++));
	memset(dp,-1,sizeof(dp));
	memset(warpA,-1,sizeof(warpA));
	memset(warpB,-1,sizeof(warpB));
	solve(0,0,-1*(1LL<<40), 0);
	printf("%d\n",rMax);
	for(int i=0;i<rMax;i++)printf("%d ",ans[i]);
}
