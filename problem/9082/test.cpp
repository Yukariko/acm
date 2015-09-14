#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

void sign(string& spec, int pos)
{
	spec[pos]--;
	if(pos)
		spec[pos-1]--;
	if(pos != spec.length() - 1)
		spec[pos+1]--;
}

bool check(const string& spec, int pos)
{
	return spec[pos] > '0' && (!pos || spec[pos-1] > '0') && (pos == spec.length()-1 || spec[pos+1] > '0');	
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		string spec;
		string mine;
		cin >> spec >> mine;

		for(int i=0; i < mine.length(); i++)
			if(mine[i] == '*')
				sign(spec, i);

		for(int i=0; i < spec.length(); i++)
		{
			if(mine[i] == '*')
				continue;
			if(check(spec, i))
			{
				mine[i] = '*';
				sign(spec, i);
			}
		}

		int ans = 0;
		for(int i=0; i < mine.length(); i++)
			ans += mine[i] == '*';
		cout << ans << '\n';
	}
	return 0;
}