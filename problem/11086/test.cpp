#include <bits/stdc++.h>

using namespace std;

int cton(char t)
{
	return t >= 'a'? t - 'a' + 10: t - '0';
}

char ntoc(int n)
{
	return n == 36? '0': n >= 10? 'a' + (n - 10): '0' + n;
}

long long base(const string& a, int b)
{
	long long ret = 0;
	for(int i=0; a[i]; i++)
		ret = (ret * b) + cton(a[i]);
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		string a, b, op, eq, c;
		cin >> a >> op >> b >> eq >> c;

		int minBase = 0;
		bool findZero = false;

		for(int i=0; a[i]; i++)
		{
			minBase = max(minBase, cton(a[i]));
			findZero |= a[i] == '0';
		}
		for(int i=0; b[i]; i++)
		{
			minBase = max(minBase, cton(b[i]));
			findZero |= a[i] == '0';
		}
		for(int i=0; c[i]; i++)
		{
			minBase = max(minBase, cton(c[i]));
			findZero |= a[i] == '0';
		}

		bool find = false;
		for(int i=minBase == 1 && !findZero? 1: minBase + 1; i <= 36; i++)
		{
			bool equal;
			switch(op[0])
			{
			case '+': equal = base(a, i) + base(b, i) == base(c, i); break;
			case '-': equal = base(a, i) - base(b, i) == base(c, i); break;
			case '*': equal = base(a, i) * base(b, i) == base(c, i); break;
			case '/': equal = base(a, i) == base(c, i) * base(b, i); break;
			}
			if(equal)
			{
				find = true;
				printf("%c", ntoc(i));
			}
		}
		if(find)
			puts("");
		else
			puts("invalid");
	}
	return 0;
}