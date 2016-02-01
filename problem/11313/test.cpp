#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	cin.ignore(1);

	vector<string> a(N);
	for(int i=0; i < N; i++)
	{
		string p, q;
		cin >> p >> q;
		a[i] = q + " " + p;
	}

	sort(a.begin(), a.end());

	int Q;
	cin >> Q;

	cin.ignore(1);

	while(Q--)
	{
		string p, q;
		cin >> p >> q;

		string s = q + " " + p;
		int idx = lower_bound(a.begin(), a.end(), s) - a.begin();
		for(int i=0; i < 3; i++)
		{
			if(idx / 3 * 3 + i != idx)
			{
				stringstream ss(a[idx / 3 * 3 + i]);
				string p, q;

				ss >> q >> p;
				cout << p << " " << q << '\n';
			}
		}
	}
	return 0;
}