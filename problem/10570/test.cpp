#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;

		int a[1002]={};

		int top=1001;
		for(int i=0; i < N; i++)
		{
			int n;
			cin >> n;
			a[n]++;
			if(a[top] < a[n])
				top = n;
			else if(a[top] == a[n] && top > n)
				top = n;
		}

		cout << top << endl;
	}
	return 0;
}