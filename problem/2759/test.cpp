#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		vector<int> ans;

		int last = N;
		while(last)
		{
			// find last
			bool find = false;
			for(int i=0; i < last - 1; i++)
				if(a[i] == last)
				{
					find = true;
					if(i)
					{
						ans.push_back(i + 1);
						reverse(a.begin(), a.begin() + i + 1);
					}
					break;
				}

			if(find == false)
			{
				last--;
				continue;
			}

			ans.push_back(last);
			reverse(a.begin(), a.begin() + last);
		}

		printf("%d ", ans.size());
		for(size_t i=0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}