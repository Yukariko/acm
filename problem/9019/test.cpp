#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const char *oper = "DSLR";

int operate(int n, char op)
{
	switch(op)
	{
	case 'D': return n * 2 % 10000;
	case 'S': return (n - 1 + 10000) % 10000;
	case 'L': return (n % 10) * 10 + (n / 10 % 10) * 100 + (n / 100 % 10) * 1000 + (n / 1000);
	case 'R': return (n % 10) * 1000 + (n / 10 % 10) + (n / 100 % 10) * 10 + (n / 1000) * 100;
	}
	return n;
}

int pre_oper[10001][4];

struct reg {
	int num;
	int ans;

	reg(int num, int ans) : num(num), ans(ans) {}
};

int solve(int A, int B, int &len)
{
	bool visit[10001] = {};
	queue<reg> q;

	q.push(reg(A,0));
	visit[A] = true;

	for(int d = 0; q.size(); d++)
	{
		int size = q.size();
		while(size--)
		{
			reg sel = q.front();
			q.pop();

			if(sel.num == B)
			{
				len = d;
				return sel.ans;
			}

			for(int i=0; i < 4; i++)
			{
				const int next = pre_oper[sel.num][i];
				if(!visit[next])
				{
					visit[next] = true;
					q.push(reg(next, (sel.ans << 2) | i));
				}
			}
		}
	}
	return 0;
}

int main()
{
	for(int i=0; i < 10000; i++)
		for(int j=0; j < 4; j++)
			pre_oper[i][j] = operate(i, oper[j]);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		int A, B;
		scanf("%d%d",&A,&B);

		int len;
		int ret = solve(A,B,len);

		string ans;
		while(len--)
		{
			ans += oper[ret & 3];
			ret >>= 2;
		}

		reverse(ans.begin(), ans.end());
		puts(ans.c_str());
	}

	return 0;
}