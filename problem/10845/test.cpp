#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;

	queue<int> q;
	while(T--)
	{
		string cmd;
		cin >> cmd;
		if(cmd == "push")
		{
			int N;
			cin >> N;
			q.push(N);
		} 
		else if(cmd == "pop")
		{
			if(q.empty())
				cout << -1 << endl;
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		} 
		else if(cmd == "size")
			cout << q.size() << endl;
		else if(cmd == "empty")
			cout << q.empty() << endl;
		else if(cmd == "front")
			cout << (q.empty()?-1:q.front()) << endl;
		else
			cout << (q.empty()?-1:q.back()) << endl;
	}

	return 0;
}