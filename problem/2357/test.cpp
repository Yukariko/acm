#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int a[N];
	for(int i=0; i < N; i++)
		cin >> a[i];

	int pack[N / 100 + 1][2];

	for(int i=0; i < N; i+=100)
	{
		int mi=1000000001, ma=0;
		int E = min(i+100, N);
		
		for(int j=i; j < E; j++)
		{
			mi = min(mi, a[j]);
			ma = max(ma, a[j]);
		}
		pack[i/100][0] = mi;
		pack[i/100][1] = ma;
	}

	while(M--)
	{
		int A, B;
		cin >> A >> B;

		A--; B--;
		int mi=1000000001, ma=0;

		int E = min(B+1, (A + 100) / 100 * 100);
		for(int i=A; i < E; i++)
		{
			mi = min(mi, a[i]);
			ma = max(ma, a[i]);
		}

		if(E == B+1)
		{
			cout << mi << " " << ma << '\n';
			continue;
		}

		E = B / 100;
		for(int i=A/100+1; i < E; i++)
		{
			mi = min(mi, pack[i][0]);
			ma = max(ma, pack[i][1]);
		}

		for(int i=B/100*100; i <= B; i++)
		{
			mi = min(mi, pack[i][0]);
			ma = max(ma, pack[i][1]);
		}

		cout << mi << " " << ma << '\n';
	}
	return 0;
}