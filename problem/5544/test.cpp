#include <iostream>
#include <algorithm>

using namespace std;

struct team {
	int score;
	int no;
	team() : score(0), no(0) {}
};

bool cmp(const team &p, const team &q)
{
	return p.score > q.score;
}

int main()
{
	int N;
	cin >> N;

	team a[N+1];
	for(int i=1; i <= N; i++)
		a[i].no = i;

	int nn = N*(N-1)/2;
	while(nn--)
	{
		int A,B,C,D;
		cin >> A >> B >> C >> D;
		if(C > D)
			a[A].score += 3;
		else if(C < D)
			a[B].score += 3;
		else
		{
			a[A].score += 1;
			a[B].score += 1;
		}
	}

	sort(a + 1, a + N + 1, cmp);

	int r[N+1];

	for(int i=1, s=1, d=0; i <= N; i++, s++)
	{
		r[a[i].no] = s - d;
		if(i != N && a[i].score == a[i+1].score)
			d++;
		else
			d = 0;
	}

	for(int i=1; i <= N; i++)
		cout << r[i] << '\n';
	return 0;
}