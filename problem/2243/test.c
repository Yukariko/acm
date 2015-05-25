#include <stdio.h>
#include <stdlib.h>

int pack[1001];
int candy[1000001];

int main()
{
  int N;
  scanf("%d",&N);
  
  for(;N--;)
  {
    int A,B,C;
    scanf("%d",&A);
    if(A == 1)
    {
      scanf("%d",&B);
      
      int ret = 0;
      int i;
      for(i=0;i<=1000;i++)
      {
        if(ret + pack[i] >= B)
          break;
        ret += pack[i];
      }
      
      for(i *= 1000; ret < B; i++)
      {
        ret += candy[i];
      }
      
      printf("%d\n",i-1);
      candy[i-1]--;
      pack[(i-1)/1000]--;
    }
    else
    {
      scanf("%d%d",&B,&C);
      candy[B] += C;
      pack[B/1000] += C;
    }
    
  }
  return 0;
}
