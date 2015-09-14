#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int direction[][4] = {
	{1, 3, -1, -1},
	{0, 2, 4, -1},
	{1, 5, -1, -1},
	{0, 4, 6, -1},
	{1, 3, 5, 7},
	{2, 4, 8, -1},
	{3, 7, -1, -1},
	{6, 4, 8, -1},
	{7, 5, -1, -1},
};

const int decimal[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int swap(int board, int pos, int npos)
{
	const int tok = ((board / decimal[npos]) % 10);
	board -= tok * decimal[npos];
	board += tok * decimal[pos];
	return board;
}

int solve(int board, int pos)
{
	queue< pair<int, int> > bfs;
	set<int> visit;

	visit.insert(board);
	bfs.push(make_pair(board, pos));
	
	int ans = 0;
	while(!bfs.empty())
	{
		size_t N = bfs.size();
		for(int i=0; i < N; i++)
		{
			pair<int,int> state = bfs.front();
			bfs.pop();

			board = state.first;
			pos = state.second;

			if(board == 123456780)
				return ans;

			for(int d=0; d < 4 && direction[pos][d] != -1; d++)
			{
				int npos = direction[pos][d];
				int nboard = swap(board, pos, npos);
				if(visit.find(nboard) != visit.end())
					continue;
				visit.insert(nboard);
				bfs.push(make_pair(nboard, npos));
			}
		}
		ans++;
	}
	return -1;
}

int main()
{
	int board = 0;
	int pos;
	for(int i=8; i >= 0; i--)
	{
		int n;
		cin >> n;
		board *= 10;
		board += n;
		if(n == 0)
			pos = i;
	}
	cout << solve(board, pos);
	return 0;
}