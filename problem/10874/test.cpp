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

	for(int T=1; T <= N; T++)
	{
		bool retest = true;
		for(int i=1; i <= 10; i++)
		{
			int answer;
			cin >> answer;
			if(answer != (i - 1) % 5 + 1)
				retest = false;
		}
		if(retest)
			cout << T << '\n';
	}
	
	return 0;
}