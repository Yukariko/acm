#define MOD 1000000000
//sum f(a) to f(b) => f(b+2) - f(a+1)
typedef struct matrix{
  long long a,b,c,d;
} matrix;

matrix mod_matrix(matrix m,long long c)
{
  m.a%=c;
  m.b%=c;
  m.c%=c;
  m.d%=c;
  return m;
}

matrix mult_matrix(matrix p,matrix q)
{
  matrix res;
  res.a = p.a * q.a + p.b * q.c;
  res.b = p.a * q.b + p.b * q.d;
  res.c = p.c * q.a + p.d * q.c;
  res.d = p.c * q.b + p.d * q.d;
  return res;
}

// m ^ b mod c
matrix greatPow(matrix m,long long b, long long c)
{
  m=mod_matrix(m,c);
  if(b==0)
  {
    m.a=m.b=m.c=m.d=0;
    return m;
  }
  if(b==1) return m;
  if(b&1) return mod_matrix(mult_matrix(m,greatPow(mult_matrix(m,m),(b-1)/2,c)),c);
  return greatPow(mult_matrix(m,m),b/2,c);
}

long long fibo(long long n)
{
  long long res;
  matrix m;
  m.a=1;m.b=1;m.c=1;m.d=0;
  if(n==1 || n==2) return 1;
  m = greatPow(m,n-2,MOD);
  res = (m.a + m.b)%MOD;
  return res;
}

main()
{
  long long a,b,res;
  scanf("%lld%lld",&a,&b);
  res = fibo(b+2)-fibo(a+1);
  if(res < 0) res += MOD;
  printf("%lld",res);
}
