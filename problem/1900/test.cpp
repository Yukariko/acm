#include <iostream>
#include <algorithm>

using namespace std;

struct player
{
	int no, pow, mag;
};

bool cmp(const player &p, const player &q)
{
	int a = p.pow + q.pow * p.mag;
	int b = q.pow + p.pow * q.mag;
	return a < b;
}

int main()
{
	int N;
	cin >> N;

	player a[10001];
	for(int i=0; i < N; i++)
	{
		a[i].no = i+1;
		cin >> a[i].pow >> a[i].mag;
	}

	sort(a, a+N, cmp);

	for(int i=0; i < N; i++)
		cout << a[i].no << endl;

	
	return 0;
}