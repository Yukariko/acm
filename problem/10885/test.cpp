#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

const int MOD = 1000000007;

long long mod_exp(long long a,long long b,long long c)
{
	a%=c;
	if(b==0)return 1;
	if(b==1)return a;
	if(b&1) return (a*mod_exp((a*a)%c,(b-1)/2,c))%c;
	return mod_exp((a*a)%c,b/2,c);
}

template<typename t>
t abs(t a)
{
	return a > 0? a: -a;
}


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		vector<int> a(N);
		for(int i=0; i < N; i++)
			cin >> a[i];
		
		vector<int> m(N);
		m[N-1] = a[N-1] < 0;
		for(int i=N-2; i >= 0; i--)
		{
			if(a[i] == 0)
				m[i] = 0;
			else
				m[i] = (a[i] < 0) + m[i+1];
		}

		bool find = false;
		int ans = 0;
		for(int i=0, next; i < N; i = next)
		{
			if(a[i] == 0)
			{
				next = i+1;
				continue;
			}

			int crnt = 0;

			next = i;
			while(next < N && a[next])
				crnt += abs(a[next++]) == 2;

			if(next - i > 1 || a[i] > 0)
				find = true;
			
			if(m[i] % 2 == 0)
				ans = max(ans, crnt);
			else
			{
				int subLeft = crnt;
				for(int j=i; j < next; j++)
				{
					subLeft -= abs(a[j]) == 2;
					if(a[j] < 0)
						break;
				}

				int subRight = crnt;
				for(int j=next-1; j >= i; j--)
				{
					subRight -= abs(a[j]) == 2;
					if(a[j] < 0)
						break;
				}
				ans = max(ans, max(subLeft, subRight));
			}
		}

		if(!find)
			cout << 0 << '\n';
		else
			cout << mod_exp(2, ans, MOD) << '\n';
	}
	return 0;
}