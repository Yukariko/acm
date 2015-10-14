#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const vector<int>& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while(begin + matched < m)
	{
		if(N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if(matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

bool kmpSearch(const vector<int>& H, const vector<int>& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	int matched = 0;
	for(int i=0; i < n; i++)
	{
		while(matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if(H[i] == N[matched])
		{
			++matched;
			if(matched == m)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N), b(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);
	for(int i=0; i < N; i++)
		scanf("%d",&b[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> diff(N);
	for(int i=1; i < N; i++)
		diff[i-1] = a[i] - a[i-1];
	diff[N-1] = (a[0] - a[N-1] + 360000) % 360000;

	for(int i=0; i < N; i++)
		diff.push_back(diff[i]);

	vector<int> diff2(N);
	for(int i=1; i < N; i++)
		diff2[i-1] = b[i] - b[i-1];
	diff2[N-1] = (b[0] - b[N-1] + 360000) % 360000;

	if(kmpSearch(diff, diff2))
		printf("possible");
	else
		printf("impossible");
	return 0;
}