#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string s;
		cin >> s;

		int N = 1;
		while(N * N < s.size())
			N++;

		vector< vector<char> > a(N, vector<char>(N, 0));
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				a[i][j] = s[i*N+j];

		for(int i=0; i < N; i++)
			for(int j=N-1; j >= 0; j--)
				if(a[j][i])
					cout << a[j][i];
		cout << '\n';
	}
	return 0;
}