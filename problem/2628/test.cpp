#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int H, W;
char a[101][101];

struct square
{
	int x1,y1,x2,y2;
};

int main()
{
	cin >> W >> H;
	int N;
	cin >> N;

	vector<square> a;

	square t;
	t.x1 = t.y1 = 0;
	t.x2 = W;
	t.y2 = H;

	a.push_back(t);
	while(N--)
	{
		int h, w;
		cin >> h >> w;

		vector<square> b;
		if(h == 0)
			for(int i=0; i < a.size(); i++)
			{
				if(a[i].y1 <= w && a[i].y2 > w)
				{
					t = a[i];
					t.y2 = w;
					b.push_back(t);
					t = a[i];
					t.y1 = w;
					b.push_back(t);
				}
				else
					b.push_back(a[i]);
			}
		else
			for(int i=0; i < a.size(); i++)
			{
				if(a[i].x1 <= w && a[i].x2 > w)
				{
					t = a[i];
					t.x2 = w;
					b.push_back(t);
					t = a[i];
					t.x1 = w;
					b.push_back(t);
				}
				else
					b.push_back(a[i]);
			}

		a = b;
	}

	int ans = 0;
	for(int i=0; i < a.size(); i++)
		ans = max(ans, (a[i].y2-a[i].y1) * (a[i].x2-a[i].x1));

	cout << ans;
	return 0;
}