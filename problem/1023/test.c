#include <math.h>
long long i,k,a;
n,j,p;
f(r)
{
	if (i & 1 == 0)
	  return 1;
	p = log2(i) + 1e-6 + 1.0;
	r = n - p;
  if (!r) 
      return 1;
	if (r > n / 2)
       return 1;
	for (j = p-1; j >= 0 && r >= 0 && r <= n/2; j--)
	{
		if ((i >> j) % 2 == 1)
			r--;
		else
			r++;
	}
		return r;
}
main()
{
    long long r,t=0;
	scanf("%d%lld", &n, &k);
	a = ((long long)1 << n);
  for(k=0;k<a;k++)
  {
    i=r=j=p=0;
  	if(n%2==0)
  	{
      i = ((long long)1 << (n / 2)) - 1;
      if ( i > k)
        i = k;
      else {
        for (r=0; i < a; i++)
        {
          if (!f(0))
          {
              r++;
          }
          if (i - r == k)
          {     
              break;
          }
        }
      }
   	}
   	else
   	{
    	i = k;
    }
  	if (i == a)
  	{
  	  t++;
  	   printf("%d",t);
  	   puts("");
  	 }
    else
    {
     // printf("[%d] ",k);
      for (r=n; r--;)
      {
        if ((i >> r) % 2 == 1)
        {
         // printf("1");
        }
        else
        {
         // printf("0");
        }
      }
    //puts("");
    }

  }
}

