#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int A, B;
	cin >> A >> B;

	int dou;
	cin >> dou;

	vector<int> topping(N);
	for(int i=0; i < N; i++)
		cin >> topping[i];

	sort(topping.begin(), topping.end(), greater<int>());

	int ans = dou / A;
	int sum = dou;
	for(int i=0; i < N; i++)
	{
		sum += topping[i];
		ans = max(ans, sum / (A + B * (i+1)));
	}
	cout << ans;
	return 0;
}