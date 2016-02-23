#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<string> a(N);
	for(int i=0; i < N; i++)
		cin >> a[i];

	bool success = true;
	for(int i=1; i < N; i++)
		if(a[i] < a[i-1])
			success = false;

	if(success == true)
	{
		puts("INCREASING");
		return 0;
	}

	success = true;
	for(int i=1; i < N; i++)
		if(a[i] > a[i-1])
			success = false;

	if(success == true)
		puts("DECREASING");
	else
		puts("NEITHER");

	return 0;
}