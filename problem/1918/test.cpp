#include <bits/stdc++.h>

using namespace std;

int main()
{
	int priority[127];
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;
	priority['('] = 3;
	priority[')'] = 3;

	char a[101];
	gets(a);

	string result;
	stack<char> oper;
	for(int i=0; a[i]; i++)
	{
		if(isalpha(a[i]))
			result += a[i];
		else
		{
			if(a[i] != ')')
			{
				while(!oper.empty() && oper.top() != '(' && priority[oper.top()] >= priority[a[i]])
				{
					result += oper.top();
					oper.pop();
				}
				oper.push(a[i]);
			}
			else
			{
				while(!oper.empty() && oper.top() != '(')
				{
					result += oper.top();
					oper.pop();
				}
				oper.pop();
			}
		}
	}
	while(!oper.empty())
	{
		result += oper.top();
		oper.pop();
	}
	cout << result;
	return 0;
}