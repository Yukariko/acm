#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int R,C;
		char a[401];
		char map[21][21];
		
		scanf("%d%d%s",&R,&C,a);
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				map[i][j] = a[i*C+j];

		int cur = 0;
		int curCount = 0;
		int count = 0;
		int len = C;
		int lenCount = 1;
		int y = 0, x = -1;
		int dy = 0, dx = 1;

		char res[101];
		int rCount = 0;
		int find = 0;
		for(;len;)
		{
			y += dy;
			x += dx;

			cur <<= 1;
			cur += map[y][x] == '1';

			curCount++;
			if(curCount == 5)
			{
				curCount = 0;
				res[rCount++] = cur==0?' ':'A'+cur-1;
				cur = 0;
			}

			count++;
			if(count == len)
			{
				count = 0;

				int t = dx;
				dx = -dy;
				dy = t;

				lenCount++;
				if(lenCount == 2)
				{
					lenCount = 0;
					C--;R--;
				}

				if(dx)
					len = C;
				else
					len = R;
			}
		}

		res[rCount] = 0;
		for(int i=rCount-1; i>=0; i--)
			if(res[i] == ' ')
				res[i] = 0;
			else
				break;
		puts(res);
	}
	return 0;
}