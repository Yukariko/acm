#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N);
	for(int i=0; i < N; i++)
		cin >> a[i];


	if(!next_permutation(a.begin(), a.end()))
		cout << -1;
	else
		for(int i=0; i < N; i++)
			cout << a[i] << " ";
	return 0;
}