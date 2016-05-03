#include <bits/stdc++.h>

using namespace std;

int lcs(const string& a, const string& b)
{
	vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));

	for(size_t i=0; i < a.size(); i++)
		for(size_t j=0; j < b.size(); j++)
		{
			if(a[i] == b[j])
				dp[i][j] = 1;
			if(j)
				dp[i][j] = max(dp[i][j], dp[i][j-1]);
			if(i)
				dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(i && j && a[i] == b[j])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
		}
	return dp[a.size()-1][b.size()-1];
}

int main()
{
	string a, b;
	while(cin >> a >> b)
		cout << lcs(a, b) << "\n";
	return 0;
}