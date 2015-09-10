#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string> a(N);
	size_t mlen = 0;
	for(int i=0; i < N; i++)
	{
		cin >> a[i];
		mlen = max(mlen, a[i].length());
	}

	for(int i=0; i < N; i++)
		while(a[i].length() != mlen)
			a[i] += '}';

	while(1)
	{
		sort(a.begin(),a.end());
		int pick = -1;
		for(int i=0; i < N; i++)
			if(a[i][0] != '}')
			{
				pick = i;
				break;
			}
		if(pick == -1)
			break;
		cout << a[pick][0];
		a[pick].erase(a[pick].begin());
		a[pick] += '}';
	}

	return 0;
}