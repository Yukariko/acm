#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

const int N = 1e5;  // limit for array size
int n;  // array size
long long t[2 * N];

int h;
long long d[N];  

void apply(int p, long long value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void build(int p) {
	while (p > 1) p >>= 1, t[p] = t[p<<1] + t[p<<1|1] + d[p];
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, long long value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

long long query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	long long res = 0;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = res + t[l++];
		if (r&1) res = t[--r] + res;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, D, S, A, B;
		scanf("%d%d%d%d%d", &N, &D, &S, &A, &B);

		memset(t, 0, sizeof(t));
		memset(d, 0, sizeof(d));

		n = N;
		h = sizeof(int) * 8 - __builtin_clz(n);

		long long ans = 0;
		int start = 0;

		for(int i=1; i <= D; i++)
		{
			int C = S % N + 1;
			S = (1LL * S * A + B) % MOD;
			int K = S % N + 1;
			S = (1LL * S * A + B) % MOD;

			if(start + C <= N)
				inc(start, start + C, i);
			else
			{
				inc(start, N, i);
				inc(0, (start + C) % N, i);
			}

			start = (start + C) % N;
			ans += query((start + K - 1) % N, (start + K - 1) % N + 1);
		}

		printf("%lld\n", ans);
	}

	return 0;
}