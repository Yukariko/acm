#include <bits/stdc++.h>

using namespace std;

char a[11];

int main()
{
	scanf("%s", a);
	vector<pair<char, int>> b;
	for(int i=0; a[i]; i++)
		b.push_back({a[i], i});

	sort(b.begin(), b.end());
	
	char s[101];
	scanf("%s", s);

	int N = strlen(a);
	int M = strlen(s);

	char c[11][101] = {};
	for(int i=0; i < N; i++)
		for(int j=0; j < M / N; j++)
			c[j][b[i].second] = s[i * M / N + j];

	for(int i=0; i < M / N; i++)
		printf("%s", c[i]);

	return 0;
}