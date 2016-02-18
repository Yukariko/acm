#include <bits/stdc++.h>

using namespace std;

struct Square
{
	int x1, y1, x2, y2;
};

bool SquareIntersect(const Square& p, const Square& q)
{
	if(q.x2 < p.x1 || p.x2 < q.x1)
		return false;

	if(q.y2 < p.y1 || p.y2 < q.y1)
		return false;

	if(p.x1 < q.x1 && q.x2 < p.x2 && p.y1 < q.y1 && q.y2 < p.y2)
		return false;

	if(q.x1 < p.x1 && p.x2 < q.x2 && q.y1 < p.y1 && p.y2 < q.y2)
		return false;
	
	return true;
}

struct DisjointSet {
	vector<int> group;
	DisjointSet(int N)
	{
		group.resize(N);
		for(int i=0; i < N; i++)
			group[i] = i;
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	void merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q)
			group[p] = q;
	}

	int group_num()
	{
		vector<bool> check(group.size(), false);
		int ans = 0;
		for(int i=0; i < group.size(); i++)
			if(check[find(i)] == false)
				check[find(i)] = true, ans++;
		return ans;
	}
};


int main()
{
	int N;
	scanf("%d", &N);

	vector<Square> a;
	a.push_back({0, 0, 0, 0});

	for(int i=0; i < N; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		a.push_back({x1, y1, x2, y2});
	}

	N = a.size();

	DisjointSet djs(N);
	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			if(SquareIntersect(a[i], a[j]))
				djs.merge(i, j);

	printf("%d", djs.group_num() - 1);
	return 0;
}