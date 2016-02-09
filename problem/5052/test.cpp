#include <bits/stdc++.h>

using namespace std;

template <char tok = '0'>
struct Trie
{
	int no;
	Trie *node[10];

	vector<int> output;

	Trie() : no(-1)
	{
		memset(node, 0, sizeof(node));
	}

	void push(const char *str, int idx)
	{
		if(*str == 0)
		{
			no = idx;
			return;
		}

		Trie *&next = node[*str-tok];
		if(next == 0)
			next = new Trie;

		return next->push(str+1, idx);
	}

	int find(const char *str)
	{
		if(*str == 0)
			return no;

		if(no != -1)
			return no;

		Trie *&next = node[*str-tok];

		if(next == 0)
		{
			return -2;
		}

		return next->find(str+1);
	}
};

string a[10001];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		for(int i=0; i < N; i++)
			cin >> a[i];

		sort(a, a + N);

		Trie<'0'> trie;
		bool success = true;
		for(int i=0; i < N; i++)
		{
			if(!success)
				continue;

			if(trie.find(a[i].c_str()) > 0)
				success = false;

			trie.push(a[i].c_str(), 1);
		}

		puts(success? "YES": "NO");
	}
	return 0;
}