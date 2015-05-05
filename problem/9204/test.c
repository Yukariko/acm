#include <stdio.h>
#include <math.h>

typedef struct chess_point
{
	char x;
	int y;
} ChessPoint;

int isDiffColor(ChessPoint p,ChessPoint q)
{
	return ((p.x - 'A' + p.y) % 2 + (q.x - 'A' + q.y) % 2) % 2;
}

int isEqual(ChessPoint p,ChessPoint q)
{
	return p.x == q.x && p.y == q.y;
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		ChessPoint p,q;
		scanf(" %c%d %c%d",&p.x,&p.y,&q.x,&q.y);

		if(isDiffColor(p,q))
		{
			puts("Impossible");
			continue;
		}

		if(isEqual(p,q))
		{
			printf("0 %c %d\n",q.x,q.y);
			continue;
		}

		if(abs(p.x - q.x) == abs(p.y - q.y))
		{
			printf("1 %c %d %c %d\n",p.x,p.y,q.x,q.y);
			continue;
		}

		int find = 0;

		for(char x = 'A'; x <= 'H'; x++)
		{
			for(int y = 1; y <= 8; y++)
			{
				if(abs(p.x - x) == abs(p.y - y) && abs(q.x - x) == abs(q.y - y))
				{
					find = 1;
					printf("2 %c %d %c %d %c %d\n",p.x,p.y,x,y,q.x,q.y);
					break;
				}
			}
			if(find) break;
		}
	}
}