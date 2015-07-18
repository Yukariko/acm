#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, E;
	long long know[101] = {};
	vector<int> a;

	cin >> N >> E;

	int new_song = 0;

	for(int i=0; i < E; i++)
	{
		int K;
		cin >> K;

		a.clear();
		for(int j=0; j < K; j++)
		{
			int P;
			cin >> P;
			a.push_back(P);
		}

		sort(a.begin(), a.end());

		if(a[0] == 1)
		{
			for(vector<int>::iterator it = a.begin(); it != a.end(); ++it)
				know[*it] |= 1LL << new_song;
			new_song++;
		}
		else
		{
			long long merge = 0;
			for(vector<int>::iterator it = a.begin(); it != a.end(); ++it)
				merge |= know[*it];

			for(vector<int>::iterator it = a.begin(); it != a.end(); ++it)
				know[*it] |= merge;
		}
	}

	for(int i=1; i <= N; i++)
		if(know[i] == (1LL << new_song) - 1)
			cout << i << endl;

	return 0;
}