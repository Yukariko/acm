#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[13][13];
bool check[13][13];
vector< pair<int,int> > line;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};

bool isOK(int y, int x)
{
	return !(y < 0 || y >= 12 || x < 0 || x >= 12 || check[y][x] || map[y][x] == '1');
}

void fill(int y, int x)
{
	check[y][x] = true;
	for(int i=0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isOK(ny, nx))
			fill(ny, nx);
	}
}

bool isTriangle(pair<int,int> point)
{
	int y = point.first;
	int x = point.second;
	int direction;
	for(int d=0; d < 4; d++)
	{
		if(map[y+dy[d]][x+dx[d]] == '1')
		{
			direction = d;
			break;
		}
	}

	if(dy[direction] == 0)
		for(int i=0; ; i++)
		{
			int nx = x + dx[direction] * i;
			int cnt = 0;
			for(int j=1; j <= 10; j++)
				if(map[j][nx] == '1')
					cnt++;

			if(!cnt)
				break;
			if(cnt != i * 2 + 1)
				return false;
		}

	else
		for(int i=0; ; i++)
		{
			int ny = y + dy[direction] * i;
			int cnt = 0;
			for(int j=1; j <= 10; j++)
				if(map[ny][j] == '1')
					cnt++;

			if(!cnt)
				break;
			if(cnt != i * 2 + 1)
				return false;
		}
	return true;
}

bool isTriangle2(pair<int,int> point)
{
	int y = point.first;
	int x = point.second;
	int direction;
	for(int d=0; d < 4; d++)
	{
		if(map[y+dy[d]][x+dx[d]] == '1')
		{
			direction = d;
			break;
		}
	}

	if(dy[direction] == 0)
		for(int i=0; ; i++)
		{
			int nx = x + dx[direction] * i;
			int cnt = 0;
			for(int j=1; j <= 10; j++)
				if(map[j][nx] == '1')
					cnt++;

			if(!cnt)
			{
				line.push_back(make_pair(y,line[1].second));
				break;
			}
			if(cnt != i + 1)
				return false;
		}

	else
		for(int i=0; ; i++)
		{
			int ny = y + dy[direction] * i;
			int cnt = 0;
			for(int j=1; j <= 10; j++)
				if(map[ny][j] == '1')
					cnt++;

			if(!cnt)
			{
				line.push_back(make_pair(line[1].first,x));
				break;
			}
			if(cnt != i + 1)
				return false;
		}
	return true;
}

int main()
{
	for(int i=1; i <= 10; i++)
		cin >> (&map[i][1]);

	fill(0,0);

	bool find = false;
	for(int i=0; i < 12; i++)
		for(int j=0; j < 12; j++)
			if(map[i][j] != '1' && check[i][j] == false)
				find = true;

	if(find)
	{
		cout << 0;
		return 0;
	}

	for(int i=1; i <= 10; i++)
	{
		for(int j=1; j <= 10; j++)
		{
			if(map[i][j] != '1')
				continue;

			int adjust = 0;
			for(int d=0; d < 4; d++)
				if(map[i+dy[d]][j+dx[d]] == '1')
					adjust++;
			if(adjust == 1)
				line.push_back(make_pair(i,j));
		}
	}

	if(line.size() == 3)
	{
		for(int i=0; i < 3; i++)
			for(int j=i+1; j < 3; j++)
				if(line[i].first == line[j].first || line[i].second == line[j].second)
					if(!isTriangle(line[6 / (i+1) / (j+1) - 1]))
					{
						cout << 0;
						return 0;
					}

		for(int i=0; i < 3; i++)
			cout << line[i].first << " " << line[i].second << endl;
	}
	else if(line.size() == 2)
	{
		if(!isTriangle2(line[0]))
		{
			cout << 0;
			return 0;
		}
		sort(line.begin(), line.end());
		for(int i=0; i < 3; i++)
			cout << line[i].first << " " << line[i].second << endl;
	}
	else
		cout << 0;

	return 0;
}