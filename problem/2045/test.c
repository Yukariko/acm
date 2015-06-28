#include <stdio.h>

int a[3][3];
int w[3][2];
int h[3][2];
int s[2][2];

int p[3][2];
int pc;

void update(int y,int x)
{
	w[y][1] |= 1<<x;
	w[y][0] += a[y][x];
	h[x][1] |= 1<<y;
	h[x][0] += a[y][x];
	if(y==x)
	{
		s[0][1] |= 1<<x;
		s[0][0] += a[y][x];
	}
	if(y == 2 - x)
	{
		s[1][1] |= 1<<x;
		s[1][0] += a[y][x];
	}
}

void delete(int y,int x)
{
	w[y][1] ^= 1<<x;
	w[y][0] -= a[y][x];
	h[x][1] ^= 1<<y;
	h[x][0] -= a[y][x];
	if(y==x)
	{
		s[0][1] ^= 1<<x;
		s[0][0] -= a[y][x];
	}
	if(y == 2 - x)
	{
		s[1][1] ^= 1<<x;
		s[1][0] -= a[y][x];
	}
}

int get()
{
	int ret = -1;
	for(int i=0;i<3;i++)
	{
		if(w[i][1] == 7)
			ret = w[i][0];
		if(h[i][1] == 7)
			ret = h[i][0];
	}
	if(s[0][1] == 7)
		ret = s[0][0];
	if(s[1][1] == 7)
		ret = s[1][0];
	return ret;
}

int check()
{
	int ret = s[0][0];
	if(ret != s[1][0])
		return 0;
	for(int i=0;i<3;i++)
		if(ret != w[i][0] || ret != h[i][0])
			return 0;
	return 1;
}

void solve(int pos)
{
	if(pos == pc)
	{
		if(check())
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
					printf("%d ",a[i][j]);
				puts("");
			}
			exit(0);
		}
		return;
	}

	int point = get();
	int y = p[pos][0];
	int x = p[pos][1];
	if(point == -1)
	{
		for(int i=1;i<=20000;i++)
		{
			a[y][x] = i;
			update(y,x);
			solve(pos+1);
			delete(y,x);
		}
	}
	else
	{
		if(w[y][1] == 7 - (1<<x))
			a[y][x] = point - w[y][0];
		else if(h[x][1] == 7 - (1<<y))
			a[y][x] = point - h[x][0];
		else if(y == x && s[0][1] == 7 - (1<<x))
			a[y][x] = point - s[0][0];
		else
			a[y][x] = point - s[1][0];
		update(y,x);
		solve(pos+1);
		delete(y,x);
	}

}

int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0)
			{
				p[pc][0] = i;
				p[pc++][1] = j;
			}
			else
				update(i,j);
		}
	}

	solve(0);
	return 0;
}