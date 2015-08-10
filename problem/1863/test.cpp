#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	stack<int> s;
	int ans = 0;

	s.push(0);
	for(int i=0;i<N;i++)
	{
		int x, y;
		cin >> x >> y;

		if(s.top() < y)
		{
			s.push(y);
			ans++;
		}

		else
		{
			while(!s.empty() && s.top() > y)
				s.pop();
			if(s.top() != y)
			{
				s.push(y);
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}