#include <bits/stdc++.h>

using namespace std;

struct matrix
{
	long long a,b,c,d;
	static const long long MOD = 1000000007LL;

	matrix() : a(0), b(0), c(0), d(0) {}
	matrix(long long a, long long b, long long c, long long d) : a(a), b(b), c(c), d(d) {}
	matrix(const matrix &mat) : a(mat.a), b(mat.b), c(mat.c), d(mat.d) {}

	matrix operator% (long long m) const
	{
		matrix ans(a,b,c,d);
		ans.a %= m;
		ans.b %= m;
		ans.c %= m;
		ans.d %= m;
		return ans;
	}

	matrix operator* (const matrix &q) const
	{
		matrix ans;
		ans.a = a * q.a + b * q.c;
		ans.b = a * q.b + b * q.d;
		ans.c = c * q.a + d * q.c;
		ans.d = c * q.b + d * q.d;
		return ans;
	}

	static matrix calcPow(matrix mat, long long p, long long m)
	{
		mat = mat % m;
		if(p == 0)
		{
			mat = matrix(0,0,0,0);
			return mat;
		}
		if(p == 1)
			return mat;

		if(p & 1)
			return (mat * calcPow(mat * mat, (p-1)/2, m)) % m;

		return calcPow(mat * mat, p/2, m);
	}

	matrix pow(long long p, long long m) const
	{
		matrix ans(a,b,c,d);
		return calcPow(ans, p, m);;
	}

	static long long fibo(long long n)
	{
		matrix m(1,1,1,0);

		if(n==1 || n==2)
			return 1;

		matrix ans = m.pow(n-2,m.MOD);
		return (ans.a + ans.b) % m.MOD;
	}
};

int main()
{
	long long N;
	scanf("%lld",&N);
	printf("%lld", matrix::fibo(N + (N % 2)));
	return 0;
}