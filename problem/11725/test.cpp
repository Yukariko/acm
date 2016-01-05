#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree(100001);
bool check[100001];

int ans[100001];

void set_tree(int parent)
{
	check[parent] = true;
	for(int i=0; i < tree[parent].size(); i++)
	{
		int& pick = tree[parent][i];
		if(check[pick] == false)
		{
			check[pick] = true;
			ans[pick] = parent;
			set_tree(pick);
		}
	}
}

int main()
{
	int N;
	scanf("%d",&N);

	for(int tc=0; tc < N; tc++)
	{
		int a, b;
		scanf("%d%d",&a,&b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	set_tree(1);

	for(int i=2; i <= N; i++)
		printf("%d\n", ans[i]);
	return 0;
}