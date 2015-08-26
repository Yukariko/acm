#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct SuffixComparator
{
	const vector<int>& group;
	int t;
	SuffixComparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
	bool operator() (int a, int b)
	{
		if(group[a] != group[b])
			return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string& s)
{
	int n = s.size();

	int t = 1;
	vector<int> group(n+1);
	for(int i=0; i < n; i++)
		group[i] = s[i];
	group[n] = -1;

	vector<int> perm(n);
	for(int i=0; i < n; i++)
		perm[i] = i;

	vector<int> newGroup(n+1);
	while(t < n)
	{
		SuffixComparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);

		t *= 2;
		if(t >= n)
			break;
		
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for(int i=1; i < n; i++)
			if(compareUsing2T(perm[i-1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i-1]];
		group = newGroup;
	}
	return perm;
}

vector<int> longestCommonPrefix(const string& s)
{
	vector<int> a = getSuffixArray(s);
	vector<int> rank(a.size());
	for(int i=0; i < a.size(); i++)
		rank[a[i]] = i;

	vector<int> ret(a.size());
	int h = 0;
	for(int i=0; i < s.size(); i++)
	{
		if(rank[i])
		{
			int j = a[rank[i]-1];
			while(s[i+h] == s[j+h])
				h++;
			ret[rank[i]] = h;
		}
		if(h)
			h--;
	}

	return ret;
}
int main()
{
	string a;
	cin >> a;

	vector<int> sfa = getSuffixArray(a);
	vector<int> lcp = longestCommonPrefix(a);

	for(int i=0; i < sfa.size(); i++)
		cout << sfa[i]+1 << " ";
	cout << '\n';

	cout << "x ";
	for(int i=1; i < lcp.size(); i++)
		cout << lcp[i] << " ";
	cout << '\n';
	return 0;
}