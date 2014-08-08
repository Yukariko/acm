#include <math.h>
long long save[1000000];
long long save2[1000000];
long long f(long long m,long long s)
{
  return s * ceil((double)m / s);
}
main()
{
  long long min, max, sq, sub;
  long long i, j, k = 0, no = 0;
  int boo;
  scanf("%lld%lld", &min, &max);
  sq = sqrt(max);
  sub=max-min;
  for (i = 2; i <= sq; i++)
  {
    if(!save[i])for(j=i*i;j<=1000000;j+=i)save[j]=1;
  }
  j=0;
  for(i=2;i<=1000000;i++)
  {
    if(!save[i])save[j++]=i*i;
  }
  for (k = 0; k < j; k++)
  {
    for (i = f(min, save[k]); i <= max; i += save[k])
    {
      save2[i-min] = 1;
    }
  }
  for (i = min; i <= max; i++)
  {
    if (save2[i-min] == 0)
      no++;
  }
  printf("%d\n", no);
}
