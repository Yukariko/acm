#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[51];
	int len = strlen(gets(a));
	sort(a, a + len);

	int b[27] = {};
	int half = (len + 1) / 2;
	for(int i=half; i < len; i++)
		b[a[i]-'a']++;

	int cnt = 1;
	for(int i=1; i < len; i++)
	{
		if(a[i-1] != a[i])
			cnt = 1;
		else
			cnt++;
		if(cnt > half)
		{
			puts("-1");
			return 0;
		}
	}

	for(int i=half; i < len; i++)
	{
		for(int j=0; j < 26; j++)
		{
			if(b[j] && a[len - i - 1] != 'a' + j)
			{
				b[j]--;
				a[i] = 'a' + j;
				break;
			}
		}
	}

	puts(a);
	return 0;
}