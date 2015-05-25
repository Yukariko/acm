#include <stdio.h>
#include <stdlib.h>

int cmp(int *p,int *q)
{
  return *p - *q;
}
int a[500001],b[500001];
int pack[2001];
int map[500001];
int main()
{
  int N;
  
  
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
    b[i] = a[i];
  }
  
  qsort(b,N,4,cmp);
  
  int max = 0;
  int maxPack = 0;
  for(int i=0;i<N;i++)
  {
    int find = (int)((int *)bsearch(&a[i],b,N,4,cmp) - b);
    int ret = 1;
    
    for(int i = find+1, z = (find + 2499) / 2500 * 2500; i < z; i++)
      ret += map[i]; 
    
    for(int i = (find + 2499) / 2500; i <= maxPack; i++)
      ret += pack[i];
    
    map[find]++;
    pack[find / 2500]++;
    if(maxPack < find / 2500)
      maxPack = find / 2500;
    
    printf("%d\n",ret);
  }
  return 0;
}
