#include <iostream>
#include <algorithm>

using namespace std;

int N,hN;
int S;
int a[41];

int s1[1<<20];
int s2[1<<20];
int s1_cnt;
int s2_cnt;

void set1(int pos, int sum)
{
	if(pos == hN)
	{
		s1[s1_cnt++] = sum;
		return;
	}

	set1(pos+1, sum);
	set1(pos+1, sum + a[pos]);
}

void set2(int pos, int sum)
{
	if(pos == N)
	{
		s2[s2_cnt++] = sum;
		return;
	}

	set2(pos+1, sum);
	set2(pos+1, sum + a[pos]);
}

int main()
{	
	cin >> N >> S;
	for(int i=0; i < N; i++)
		cin >> a[i];

	hN = N / 2;

	set1(0,0);
	set2(hN,0);

	sort(s1, s1+s1_cnt);
	sort(s2, s2+s2_cnt);


	long long ret = 0;
	for(int i=0; i < s1_cnt; i++)
	{
		int *low = lower_bound(s2, s2+s2_cnt, S - s1[i]);
		int *up = upper_bound(s2, s2+s2_cnt, S - s1[i]);
		if(low && up)
			ret += (int)(up - low);
	}
	cout << ret - (S==0);
	return 0;
}