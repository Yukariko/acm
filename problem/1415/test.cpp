#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool numSet[500001];
int b[10001];

vector<int> c;
vector< vector<long long> > cache;

long long solve(int pos, int sum)
{
	if(pos == c.size())
		return !numSet[sum];

	long long& ret = cache[pos][sum];
	if(ret != -1)
		return ret;
	ret = 0;
	int n = c[pos];
	for(int i=0; i <= b[n]; i++)
		ret += solve(pos+1, sum + n * i);
	return ret;
}

int main()
{
	numSet[0] = numSet[1] = true;
	for(long long i=2; i <= 500000; i++)
		if(numSet[i] == false)
			for(long long j=i*i; j <= 500000; j+=i)
				numSet[j] = true;

	cin >> N;
	for(int i=0; i < N; i++)
	{
		int n;
		cin >> n;
		b[n]++;
	}

	for(int i=0; i <= 10000; i++)
		if(b[i])
			c.push_back(i);

	cache = vector< vector<long long> >(c.size());

	int sum = 0;
	int cp = 0;
	for(int i=0; i <= 10000; i++)
	{
		if(b[i])
		{
			sum += i * b[i];
			cache[cp++] = vector<long long>(sum+1, -1);
		}
	}
	cout << solve(0,0);
	return 0;
}