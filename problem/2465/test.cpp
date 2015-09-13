#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

template<typename KeyType = int>
class treap
{
	struct Node
	{
		KeyType key;
		int priority, size;
		Node *left, *right;

		Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}

		void setLeft(Node *newLeft)
		{
			left = newLeft;
			calcSize();
		}
		void setRight(Node *newRight)
		{
			right = newRight;
			calcSize();
		}

		void calcSize()
		{
			size = 1;
			if(left)
				size += left->size;
			if(right)
				size += right->size;
		}
	};
	Node *root;
public:

	treap() : root(NULL) {}
	void insert(KeyType key)
	{
		Node *node = new Node(key);
		root = insert(root, node);
	}
	void erase(KeyType key)
	{
		root = erase(root, key);
	}
	KeyType kth(int k)
	{
		return kth(root, k)->key;
	}
	int countLessThan(KeyType key)
	{
		return countLessThan(root, key);
	}

private:
	typedef pair<Node*,Node*> NodePair;
	NodePair split(Node *root, KeyType key)
	{
		if(root == NULL)
			return NodePair(NULL, NULL);
		if(root->key < key)
		{
			NodePair rs = split(root->right, key);
			root->setRight(rs.first);
			return NodePair(root, rs.second);
		}
		NodePair ls = split(root->left, key);
		root->setLeft(ls.second);
		return NodePair(ls.first, root);
	}

	Node *insert(Node *root, Node *node)
	{
		if(root == NULL)
			return node;

		if(root->priority < node->priority)
		{
			NodePair splitted = split(root, node->key);
			node->setLeft(splitted.first);
			node->setRight(splitted.second);
			return node;
		}
		else if(node->key < root->key)
			root->setLeft(insert(root->left, node));
		else
			root->setRight(insert(root->right, node));
		return root;
	}
	Node *merge(Node *a, Node *b)
	{
		if(a == NULL)
			return b;
		if(b == NULL)
			return a;
		if(a->priority < b->priority)
		{
			b->setLeft(merge(a, b->left));
			return b;
		}
		a->setRight(merge(a->right, b));
		return a;
	}

	Node *erase(Node *root, KeyType key)
	{
		if(root == NULL)
			return root;

		if(root->key == key)
		{
			Node *ret = merge(root->left, root->right);
			delete root;
			return ret;
		}
		if(key < root->key)
			root->setLeft(erase(root->left, key));
		else
			root->setRight(erase(root->right, key));
		return root;
	}
	Node *kth(Node *root, int k)
	{
		int leftSize = 0;
		if(root->left != NULL)
			leftSize = root->left->size;
		if(k <= leftSize)
			return kth(root->left, k);
		if(k == leftSize + 1)
			return root;
		return kth(root->right, k - leftSize - 1);
	}
	int countLessThan(Node *root, KeyType key)
	{
		if(root == NULL)
			return 0;
		if(root->key >= key)
			return countLessThan(root->left, key);
		int ls = (root->left? root->left->size : 0);
		return ls + 1 + countLessThan(root->right, key);
	}
};

int main()
{
	int N;
	scanf("%d",&N);

	treap<int> tree;
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		tree.insert(n);
	}

	vector<int> s(N);
	for(int i=0; i < N; i++)
		scanf("%d",&s[i]);

	vector<int> ans(N);
	for(int i=N-1; i >= 0; i--)
	{
		ans[i] = tree.kth(s[i]+1);
		tree.erase(ans[i]);
	}

	for(int i=0; i < N; i++)
		printf("%d\n",ans[i]);
	
	return 0;
}