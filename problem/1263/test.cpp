#include <iostream>
#include <algorithm>

using namespace std;

struct work
{
	int t,s;
};

bool cmp(const work &p,const work &q)
{
	if(p.s != q.s)
		return p.s < q.s;
	return p.t < q.t;
}

int main()
{
	int N;
	work w[1001];
	
	cin >> N;
	for(int i=0; i < N; i++)
		cin >> w[i].t >> w[i].s;

	sort(w, w+N, cmp);

	int start=0, end=1000000;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		bool possible = true;
		int t = mid;
		for(int i=0; i < N; i++)
		{
			if(t + w[i].t > w[i].s)
			{
				possible = false;
				break;
			}
			t += w[i].t;
		}

		if(possible)
			start = mid + 1;
		else
			end = mid - 1;
	}

	cout << end;
	return 0;
}