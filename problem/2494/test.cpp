#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int N;
char a[10001];
char b[10001];

int cache[10001][10];
int choose[10001][10];
int solve(int pos, int rotate)
{
	if(pos == N)
		return 0;

	const int num = (a[pos] - '0' + rotate) % 10;

	int& ret = cache[pos][rotate];
	if(ret != -1)
		return ret;

	int left = b[pos] - '0' - num;
	if(left < 0)
		left += 10;
	int right = 10 - left;
	
	ret = left + solve(pos+1, (rotate + left) % 10);
	choose[pos][rotate] = left;

	int cross = right + solve(pos+1, rotate);
	if(ret > cross)
	{
		ret = cross;
		choose[pos][rotate] = -right;
	}
	return ret;
}

void solve2(int pos, int rotate)
{
	if(pos == N)
		return;

	cout << pos+1 << " " << choose[pos][rotate] << '\n';
	if(choose[pos][rotate] < 0)
		solve2(pos+1, rotate);
	else
		solve2(pos+1, (rotate + choose[pos][rotate]) % 10);
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cin >> a >> b;
	cout << solve(0, 0) << endl;	
	solve2(0, 0);
	return 0;
}