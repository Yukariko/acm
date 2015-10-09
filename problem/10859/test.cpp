#include <bits/stdc++.h>

using namespace std;

const int trans[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

bool isPrime(long long n)
{
	if(n == 1)
		return false;
	for(long long i=2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int main()
{
	string s;
	cin >> s;

	long long a = atoll(s.c_str());

	for(int i=0; s[i]; i++)
	{
		if(trans[s[i]-'0'] == -1)
		{
			cout << "no";
			return 0;
		}
		s[i] = trans[s[i]-'0'] + '0';
	}

	reverse(s.begin(), s.end());

	while(s[0] == '0')
		s.erase(s.begin());

	long long b = atoll(s.c_str());

	if(isPrime(a) && isPrime(b))
		cout << "yes";
	else
		cout << "no";
	return 0;
}