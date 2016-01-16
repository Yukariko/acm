#include <bits/stdc++.h>

using namespace std;

void base(int num, int base, vector<int>& save)
{
	while(num)
	{
		save.push_back(num % base);
		num /= base;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int B, X, Y;
		scanf("%d%d%d", &B, &X, &Y);

		vector<int> XtoB, YtoB;
		base(X, B, XtoB);
		base(Y, B, YtoB);

		vector<int> numSum;
		for(int i=0; i < XtoB.size() || i < YtoB.size(); i++)
		{
			int num = 0;
			if(i < XtoB.size())
				num += XtoB[i];
			if(i < YtoB.size())
				num += YtoB[i];

			numSum.push_back(num % B);
		}

		reverse(numSum.begin(), numSum.end());

		int ans = 0;
		for(int i=0; i < numSum.size(); i++)
		{
			ans *= B;
			ans += numSum[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}