#include <stdio.h>

int a[500001];
int b[500001];
int main()
{
    a[0] = 987654321;
    int N;
    scanf("%d",&N);
    int max = 0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        if(max < a[i])
        {
            max = a[i];
            printf("0 ");
        }
        else
        {
            int dst=i-1;
            for(;a[dst] < a[i];dst = b[dst]);
            b[i]=dst;
            printf("%d ",dst);
        }
    }
    return 0;
}
