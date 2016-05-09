#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	char a[100001];
	scanf("%s", a);

	int freq[26] = {};
	for(int i=0; i < N && a[i]; i++)
	{
		putchar(a[i]);
		freq[a[i]-'a']++;
	}

	for(int i=N; a[i]; i++)
	{
		int pos = (int)(max_element(freq, freq+26)-freq);
		putchar((pos + 1 + a[i] - 'a') % 26 + 'a');
		freq[a[i-N]-'a']--;
		freq[a[i]-'a']++;
	}
	return 0;
}