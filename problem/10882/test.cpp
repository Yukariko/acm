#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int H, M;
	double D;
	char pm;
	scanf("%d:%d %*c%*c%*c%c%lf",&H,&M,&pm,&D);

	if(pm == '-')
		D = -D;

	int m = H * 60 + M - (int)(D * 60);
	if(m < 0)
		m += 24 * 60;
	if(m >= 24 * 60)
		m -= 24 * 60;

	while(T--)
	{
		double ND;
		scanf(" %*c%*c%*c%c%lf",&pm,&ND);
		if(pm == '-')
			ND = -ND;

		int nm = m + (int)(ND * 60);
		if(nm < 0)
			nm += 24 * 60;
		if(nm >= 24 * 60)
			nm -= 24 * 60;

		printf("%.2d:%.2d\n",nm / 60, nm % 60);
	}

	return 0;
}