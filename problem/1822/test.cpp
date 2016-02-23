#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> a(N), b(M);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < M; i++)
		scanf("%d", &b[i]);

	sort(b.begin(), b.end());

	vector<int> ans;
	for(int i=0; i < N; i++)
		if(!binary_search(b.begin(), b.end(), a[i]))
			ans.push_back(a[i]);

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());
	for(size_t i=0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}