#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int ans = 0;
	for(int i=0; b[i]; i++)
	{
		int maxMatch = -1;
		for(int j=0; a[j]; j++)
			for(int k=0; a[j+k] && b[i+k] && a[j+k] == b[i+k]; k++)
				maxMatch = max(maxMatch, k);
		
		i += maxMatch;
		ans++;
	}

	cout << ans;
	return 0;
}