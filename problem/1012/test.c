#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int R,C;
char map[51][51];
 
const int d[2][4] = {
    {0,0,-1,1},
    {1,-1,0,0}
};
 
void dfs(int y, int x)
{
    if(y < 0 || x < 0 || y >= R || x >= C || !map[y][x])
        return;
 
    map[y][x] = 0;
 
    for(int i=0;i<4;i++)
        dfs(y+d[0][i],x+d[1][i]);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    for(;T--;)
    {
        int K;
        scanf("%d%d%d",&C,&R,&K);
 
        for(int i=0;i<K;i++)
        {
            int X,Y;
            scanf("%d%d",&X,&Y);
            map[Y][X] = 1;
        }
 
        int ret = 0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(map[i][j] == 1)
                {
                    ret++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}

