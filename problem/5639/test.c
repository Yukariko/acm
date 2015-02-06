int N,M;
int node[10001];
int tree[10001][2];
void makeTree(int pos, int newNode)
{
	if(tree[pos][0] == -1 && node[pos] > node[newNode])
	{
		tree[pos][0] = newNode;
		return;
	}
	if(tree[pos][1] == -1 && node[pos] < node[newNode])
	{
		tree[pos][1] = newNode;
		return;
	}
	if(tree[pos][0] != -1 && node[pos] > node[newNode])
	{
		makeTree(tree[pos][0],newNode);
	}
	if(tree[pos][1] != -1 && node[pos] < node[newNode])
	{
		makeTree(tree[pos][1],newNode);
	}
}
int solve(int pos)
{
	if(pos == N)return 0;
	if(tree[pos][0] != -1)
		solve(tree[pos][0]);
	if(tree[pos][1] != -1)
		solve(tree[pos][1]);
	printf("%d\n",node[pos]);
}

main()
{
	memset(tree,-1,sizeof(tree));
	for(;~scanf("%d",&node[N]);N++)
		makeTree(0,N);
	solve(0);
}
