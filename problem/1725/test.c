int N;
long long fence[100001];
long long min(long long a,long long b){return a>b?b:a;}
long long max(long long a,long long b){return a>b?a:b;}

long long cutting(int left, int right)
{
	if(left == right) return fence[left];
	const int mid = (left+right)/2;
	long long ret = max(cutting(left,mid),cutting(mid+1,right));

	int pLeft = mid;
	int pRight = mid+1;
	long long len = min(fence[pLeft],fence[pRight]);
	ret = max(ret,len * 2);
	for(;pLeft > left || pRight < right;)
	{
		// 0 - left, 1 - right
		int select;
		if(pLeft == left) select = 1;
		else if(pRight == right) select = 0;
		else select = fence[pLeft - 1] < fence[pRight + 1];
		if(select == 0)
		{
			pLeft--;
			len = min(len,fence[pLeft]);
		}
		else
		{
			pRight++;
			len = min(len,fence[pRight]);
		}
		ret = max(ret,(pRight - pLeft + 1) * len);
	}
	return ret;
}

main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&fence[i]);
	}
	printf("%lld\n",cutting(0,N-1));
}
