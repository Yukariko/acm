#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct SegmentTree
{
	int n;
	int h;
	T init;
	vector<T> t, d;

	SegmentTree(const vector<T>& a, T init) : n(a.size()), init(init)
	{
		t.resize(2 * n);
		for(int i=0; i < n; i++)
			t[i + n] = a[i];
		build();

		d.resize(n, 0);
		h = sizeof(int) * 8 - __builtin_clz(n);
	}

	inline T combine(const T& p, const T& q)
	{
		return p + q;
	}

	void build()
	{
		for(int i=n-1; i > 0; i--)
			t[i] = combine(t[i << 1], t[i << 1 | 1]);
	}

	T query(int l, int r)
	{
		push(l, l + 1);
		push(r - 1, r);
		T res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l&1) res += t[l++];
			if (r&1) res += t[--r];
		}
		return res;
	}

	//Lazy Propagation
	void calc(int p, int k)
	{
		if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
		else t[p] = d[p] * k;
	}

	void apply(int p, const T& value, int k)
	{
		t[p] += value * k;
		if (p < n) d[p] += value;
	}
	
	void build(int l, int r)
	{
		int k = 2;
		for (l += n, r += n-1; l > 1; k <<= 1)
		{
			l >>= 1, r >>= 1;
			for (int i = r; i >= l; --i) calc(i, k);
		}
	}

	void push(int l, int r)
	{
		int s = h, k = 1 << (h-1);
		for (l += n, r += n-1; s > 0; --s, k >>= 1)
			for (int i = l >> s; i <= r >> s; ++i) 
				if (d[i] != 0)
				{
					apply(i<<1, d[i], k);
					apply(i<<1|1, d[i], k);
					d[i] = 0;
				}
	}

	void inc(int l, int r, int value)
	{
		if (value == 0) return;
		push(l, l + 1);
		push(r - 1, r);
		bool cl = false, cr = false;
		int k = 1;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1)
		{
			if (cl) calc(l - 1, k);
			if (cr) calc(r, k);
			if (l&1) apply(l++, value, k), cl = true;
			if (r&1) apply(--r, value, k), cr = true;
		}
		for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1)
		{
			if (cl) calc(l, k);
			if (cr && (!cl || l != r)) calc(r, k);
		}
	}
};

int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	vector<long long> a(N);
	for(int i=0; i < N; i++)
		scanf("%lld", &a[i]);

	SegmentTree<long long> st(a, 0);
	for(int i=0; i < M + K; i++)
	{
		int C, P, Q;
		scanf("%d%d%d", &C, &P, &Q);
		if(C == 1)
		{
			long long S;
			scanf("%lld", &S);
			st.inc(P - 1, Q, S);
		}
		else
			printf("%lld\n", st.query(P-1, Q));
	}
	return 0;
}