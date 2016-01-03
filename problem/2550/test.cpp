#include <bits/stdc++.h>

using namespace std;

vector<int> lis(const vector<int>& a)
{
	int N = a.size();
	vector<int> b;
	vector<int> apos;
	vector<int> parent(N);
	
	fill(parent.begin(), parent.end(), -1);

	for(int i=0; i < N; i++)
	{
		int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if(idx == b.size())
		{
			b.push_back(a[i]);
			apos.push_back(i);
			if(apos.size() > 1)
				parent[i] = apos[apos.size()-2];
		}
		else
		{
			b[idx] = a[i];
			apos[idx] = i;
			if(idx)
				parent[i] = apos[idx-1];
		}
	}

	int child = apos.back();
	for(int i=apos.size()-1; child != -1; i--)
	{
		b[i] = a[child];
		child = parent[child];
	}

	return b;
}

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N), b(N), mark(N);
	for(int i=0; i < N; i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
		mark[a[i]] = i;
	}

	for(int i=0; i < N; i++)
	{
		scanf("%d",&b[i]);
		b[i]--;
		a[mark[b[i]]] = i;
	}

	vector<int> ans = lis(a);
	for(auto &pick : ans)
		pick = b[pick] + 1;

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for(auto &pick : ans)
		printf("%d ", pick);
	return 0;
}