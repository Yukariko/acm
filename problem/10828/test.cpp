#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	stack<int> stk;

	while(N--)
	{
		string op;
		int X;

		cin >> op;
		if(op == "push")
		{
			cin >> X;
			stk.push(X);
		}
		else if(op == "top")
		{
			if(stk.empty())
				cout << -1 << endl;
			else
				cout << stk.top() << endl;
		}
		else if(op == "size")
			cout << stk.size() << endl;
		else if(op == "empty")
			cout << stk.empty() << endl;
		else if(op == "pop")
		{
			if(stk.empty())
				cout << -1 << endl;
			else
			{
				cout << stk.top() << endl;		
				stk.pop();
			}
		}
	}
	return 0;
}