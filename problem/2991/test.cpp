#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int A,B,C,D;
	vector<int> a(1000, 0);

	cin >> A >> B >> C >> D;
	for(int i=0; i < 1000; i++)
	{
		if(i % (A+B) < A)
			a[i+1]++;
		if(i % (C+D) < C)
			a[i+1]++;
	}

	for(int i=0; i < 3; i++)
	{
		int N;
		cin >> N;
		cout << a[N] << endl;
	}
	return 0;
}