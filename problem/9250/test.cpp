#include <bits/stdc++.h>

using namespace std;

const int NUM = 26;
int toNum(char ch) {return ch - 'a';}

struct TrieNode
{
	int terminal;
	TrieNode* children[NUM];
	TrieNode *fail;
	vector<int> output;

	TrieNode() : terminal(-1), fail(NULL)
	{
		memset(children, 0, sizeof(children));
	}

	~TrieNode()
	{
		for(int i=0; i < NUM; i++)
			if(children[i])
				delete children[i];
	}

	void insert(const char* key, int id)
	{
		if(*key == 0)
			terminal = id;
		else
		{
			int next = toNum(*key);
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key+1, id);
		}
	}

	TrieNode* find(const char* key)
	{
		if(*key == 0)
			return this;
		int next = toNum(*key);
		if(children[next] == NULL)
			return NULL;
		return children[next]->find(key+1);
	}

	static void computeFailFunc(TrieNode *root)
	{
		queue<TrieNode*> q;
		root->fail = root;
		q.push(root);

		while(!q.empty())
		{
			TrieNode* here = q.front();
			q.pop();

			for(int edge=0; edge < NUM; edge++)
			{
				TrieNode* child = here->children[edge];
				if(!child)
					continue;
				if(here == root)
					child->fail = root;
				else
				{
					TrieNode* t = here->fail;
					while(t != root && t->children[edge] == NULL)
						t = t->fail;
					if(t->children[edge])
						t = t->children[edge];
					child->fail = t;
				}

				child->output = child->fail->output;
				if(child->terminal != -1)
					child->output.push_back(child->terminal);
				q.push(child);
			}
		}
	}

	static vector<pair<int,int>> ahoCorasick(const char* s, TrieNode* root)
	{
		vector<pair<int,int>> ret;
		TrieNode* state = root;

		for(size_t i=0; s[i]; i++)
		{
			int chr = toNum(s[i]);
			while(state != root && state->children[chr] == NULL)
				state = state->fail;
			if(state->children[chr])
				state = state->children[chr];
			for(size_t j=0; j < state->output.size(); j++)
				ret.push_back(make_pair(i, state->output[j]));
		}
		return ret;
	}
};

int main()
{
	TrieNode trie;
	int N;
	scanf("%d",&N);

	while(N--)
	{
		char a[101];
		scanf("%s",a);
		trie.insert(a, 1);
	}

	TrieNode::computeFailFunc(&trie);

	int M;
	scanf("%d",&M);
	while(M--)
	{
		char a[10001];
		scanf("%s",a);
		auto ans = TrieNode::ahoCorasick(a, &trie);
		if(ans.empty())
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}