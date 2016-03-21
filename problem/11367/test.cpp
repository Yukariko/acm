#include <bits/stdc++.h>

using namespace std;

const char *grade[] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};
const int part[] = {97, 90, 87, 80, 77, 70, 67, 60, 0};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		char a[101];
		int N;
		scanf("%s%d", a, &N);

		int ans = 0;
		while(part[ans] > N)
			ans++;
		printf("%s %s\n", a, grade[ans]);
	}
	return 0;
}