#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long gcd(long long p, long long q)
{
	return q? gcd(q, p % q): p;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;

		vector<long long> a(N);
		for(int i=0; i < N; i++)
			cin >> a[i];

		map<long long, int> gcds;
		long long ans = 0;

		map<long long, int> cnt;

		for(int i=0; i < N; i++)
		{
			map<long long, int> check;
			check[a[i]]++;
			for(map<long long, int>::iterator	it = gcds.begin(); it != gcds.end(); ++it)
			{
				long long cand = gcd(a[i], it->first);
				check[cand] = max(check[cand], it->second + 1);
			}

			for(map<long long, int>::iterator	it = gcds.begin(); it != gcds.end(); ++it)
				if(check.find(it->first) == check.end())
					ans = max(ans, it->first * it->second);

			gcds = check;

			for(map<long long, int>::iterator	it = gcds.begin(); it != gcds.end(); ++it)
				cout << it->first << "," << it->second << " ";
			cout << endl;
		}
		for(map<long long, int>::iterator	it = gcds.begin(); it != gcds.end(); ++it)
			ans = max(ans, it->first * it->second);
		cout << ans << '\n';
	}
	return 0;
}