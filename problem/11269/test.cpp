#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ans = 0;
	for(int i=0; s[i]; )
		for(int j=0; "PER"[j]; j++, i++)
			ans += s[i] != "PER"[j];

	printf("%d",ans);
	return 0;
}