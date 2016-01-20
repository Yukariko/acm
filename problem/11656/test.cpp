#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[1001];
	gets(a);

	vector<string> b;
	for(int i=0; a[i]; i++)
		b.push_back(a + i);

	sort(b.begin(), b.end());
	for(size_t i=0; i < b.size(); i++)
		puts(b[i].c_str());
	return 0;
}