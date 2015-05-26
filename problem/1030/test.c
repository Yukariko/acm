#include <stdio.h>
 
int s,N,K;
 
int nPow(int n)
{
    int ret = 1;
    for(int i=0;i<n;i++)
        ret *= N;
    return ret;
}
 
int getFractal(int time, int y, int x)
{
    if(time == 0)
        return 0;
     
    int tok = nPow(time-1);
    int parity = (N-K)/2;   
 
    if(y/tok >= parity && y/tok < N - parity && x/tok >= parity && x/tok < N - parity)
        return 1;
 
    return getFractal(time-1, y - y / tok * tok, x - x / tok * tok);
}
 
int main()
{
    int R1,R2,C1,C2;
    scanf("%d%d%d",&s,&N,&K);       
    scanf("%d%d%d%d",&R1,&R2,&C1,&C2);
     
    for(int i=R1; i <= R2; i++)
    {
        for(int j=C1; j <= C2; j++)
        {
            printf("%d",getFractal(s,i,j));
        }
        puts("");
    }
    return 0;
}

