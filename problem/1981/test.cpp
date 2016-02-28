#include <bits/stdc++.h>

using namespace std;

int N;
int a[101][101];

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool visit[201][101][101];

struct node
{
    int y, x, ma;
};

int pass(int minimum)
{
    memset(visit, false, sizeof(visit));
    queue<node> bfs;
    bfs.push({0, 0, a[0][0]});
    visit[a[0][0]][0][0] = true;

    int ans = 201;

    while(!bfs.empty())
    {
        int y = bfs.front().y;
        int x = bfs.front().x;
        int ma = bfs.front().ma;
        bfs.pop();

        if(y == N-1 && x == N-1)
        {
            ans = min(ans, ma - minimum);
            continue;
        }

        for(int d=0; d < 4; d++)
        {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] < minimum)
                continue;

            int nma = max(ma, a[ny][nx]);

            if(visit[nma][ny][nx])
                continue;

            visit[nma][ny][nx] = true;
            bfs.push({ny, nx, nma});
        }
    }

    return ans;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            scanf("%d", &a[i][j]);

    int left = 0, right = a[0][0];


    int ans = 201;
    while(left <= right)
    {
        ans = min(ans, pass(left));
        left++;
    }

    printf("%d", ans);
    return 0;
}