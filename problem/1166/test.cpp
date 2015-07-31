#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int N, L, W, H;
	cin >> N >> L >> W >> H;

	double start = 1e-11, end = min(min(L,W),H);
	double ans = 0;
	while(fabs(end - start) > 1e-10)
	{
		double mid = (start + end) / 2;
		double push = floor(L / mid) * floor(W / mid) * floor(H / mid) + 1e-9;

		if(push >= N)
		{
			start = mid;
			ans = max(ans, mid);
		}
		else if(push < N)
			end = mid;
	}

	cout.setf(ios::fixed);
	cout.precision(10);
	cout << ans;
	return 0;
}