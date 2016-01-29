#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	char a[2001], b[2001];
	for(int i=0; i < N; i++)
		scanf(" %c", &a[i]);

	int left = 0, right = N-1;
	for(int i=0; i < N;)
	{
		if(a[left] < a[right])
			b[i++] = a[left++];
		else if(a[left] > a[right])
			b[i++] = a[right--];
		else
		{
			int l = left;
			int r = right;

			while(l < r && a[l] == a[r])
				l++, r--;

			if(l >= r)
				b[i++] = a[left++];
			else if(a[l] < a[r])
				b[i++] = a[left++];
			else
				b[i++] = a[right--];
		}
	}

	for(int i=0; i < N; i++)
	{
		putchar(b[i]);
		if(i % 80 == 79)
			puts("");
	}

	return 0;
}