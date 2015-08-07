#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

struct wTree
{
	bool end;
	int no;
	wTree *node[26];

	wTree() : end(false), no(-1)
	{
		memset(node, 0, sizeof(node));
	}

	void push(string &str, int idx, int sIdx=0)
	{
		if(str[sIdx] == 0)
		{
			no = idx;
			return;
		}

		wTree *&next = node[str[sIdx]-'A'];
		if(next == 0)
			next = new wTree;

		return next->push(str, idx, sIdx+1);
	}

	int find(char *str, int sIdx=0)
	{
		if(str[sIdx] == 0)
			return no;

		wTree *&next = node[str[sIdx]-'A'];

		if(next == 0)
			return -2;

		return next->find(str, sIdx+1);
	}
};

wTree root;

const int score[] = {0,0,0,1,1,2,3,5,11};
const int dx[] = {1, 1,1,-1,-1,-1,0, 0};
const int dy[] = {1,-1,0, 1,-1, 0,1,-1};

int N;
string a[300001];

char board[4][5];
bool found[300001];
bool visit[4][4];

int cnt;
int longest;

bool inRange(int x, int y)
{
	return !(x < 0 || x >= 4 || y < 0 || y >= 4 || visit[y][x]);
}

char str[10];

int solve(const int &x, const int &y, int depth)
{
	str[depth]=0;
	int ret = root.find(str);
	if(ret == -2)
		return 0;

	if(ret != -1 && found[ret] == false)
	{
		found[ret] = true;
		cnt++;

		if(longest == N)
			longest = ret;
		else if(a[longest].length() < a[ret].length())
			longest = ret;
		else if(a[longest].length() == a[ret].length())
			longest = min(ret, longest);

		ret = score[a[ret].length()];
	}
	else
		ret = 0;

	visit[y][x] = true;

	for(int d=0; d < 8; d++)
	{
		int X = x + dx[d];
		int Y = y + dy[d];
		if(inRange(X,Y))
		{
			str[depth] = board[Y][X];
			ret += solve(X,Y,depth+1);
		}
	}

	visit[y][x] = false;
	return ret;
}

int main()
{	
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a, a+N);

	for(int i=0; i < N; i++)
		root.push(a[i], i);

	int T;
	scanf("%d ",&T);
	while(T--)
	{
		memset(found, 0, sizeof(found));
		cnt = 0;
		longest=N;

		for(int i=0; i < 4; i++)
			gets(board[i]);

		int score=0;
		for(int i=0; i < 4; i++)
		{
			for(int j=0; j < 4; j++)
			{
				str[0] = board[i][j];
				score += solve(j,i,1);
			}
		}

		printf("%d %s %d\n",score,a[longest].c_str(),cnt);
		gets(board[0]);
	}
	return 0;
}