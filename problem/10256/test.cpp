#include <bits/stdc++.h>

using namespace std;

const int NUM = 4;
int toNum(char ch)
{
	switch(ch)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	}
}

struct TrieNode
{
	int terminal;
	TrieNode* children[NUM];
	TrieNode *fail;
	int output;

	TrieNode() : terminal(-1), fail(NULL), output(0)
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
					child->output += 1;
				q.push(child);
			}
		}
	}

	static int ahoCorasick(const char* s, TrieNode* root)
	{
		int ret = 0;
		TrieNode* state = root;

		for(size_t i=0; s[i]; i++)
		{
			int chr = toNum(s[i]);
			while(state != root && state->children[chr] == NULL)
				state = state->fail;
			if(state->children[chr])
				state = state->children[chr];
			ret += state->output;
		}
		return ret;
	}
};

int N, M;
char a[1000001];
char b[101];

bool visit[101][101];

void mark(TrieNode& trie, int left, int right)
{
	if(left + 1 >= right)
		return;
	if(visit[left][right])
		return;
	visit[left][right] = true;

	reverse(b + left, b + right);
	trie.insert(b, 1);
	reverse(b + left, b + right);
	mark(trie, left + 1, right);
	mark(trie, left, right - 1);
} 

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d%d",&N,&M);
		scanf("%s%s", a, b);

		memset(visit, false, sizeof(visit));

		TrieNode trie;
		trie.insert(b, 1);
		mark(trie, 0, M);
		TrieNode::computeFailFunc(&trie);
		printf("%d\n", TrieNode::ahoCorasick(a, &trie));
	}
	return 0;
}