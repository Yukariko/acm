#include <bits/stdc++.h>

using namespace std;

struct team
{
	string school, name;
	int solve, penalty;

	bool operator < (const team& q) const
	{
		if(solve != q.solve)
			return solve > q.solve;
		return penalty < q.penalty;
	}
};

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<team> a(N);
	for(int i=0; i < N; i++)
		cin >> a[i].school >> a[i].name >> a[i].solve >> a[i].penalty;

	sort(a.begin(), a.end());

	set<string> check;

	int pick = 0;
	for(int i=0; pick < K; i++)
	{
		if(check.count(a[i].school))
			continue;
		check.insert(a[i].school);
		puts(a[i].name.c_str());
		pick++;
	}

	return 0;
}