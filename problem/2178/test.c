#include <stdio.h>

typedef struct coord{
	int x,y;
} DATA;

typedef struct queue{
	DATA data;
	struct queue *next;
} Queue;

Queue *head,*tail;

void push(DATA val)
{
	tail->data=val;
	tail->next=(Queue *)malloc(sizeof(Queue));
	tail=tail->next;
	tail->next=0;
}
DATA pop()
{
	Queue *p=head;
	DATA result=head->data;
	head=head->next;
	free(p);
	return result;
}
int isEmpty()
{
	return !head;
}
void init()
{
	head=(Queue *)malloc(sizeof(Queue));
	head->next=0;
	tail=head;
}

const int D[2][4] = {
	{0,0,1,-1},
	{1,-1,0,0}
};

int main()
{
	char map[101][101];
	int N,M;
	
	init();
	scanf("%d%d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf(" %c",&map[i][j]);
			map[i][j]-=48;
		}
	}
	
	DATA t;
	t.x=1;t.y=1;
	push(t);
	
	for(int s=1,k=1;;s++)
	{
		int p = k;
		k = 0;
		while(p--)
		{
			DATA pick=pop();
			if(pick.x == N && pick.y == M)
			{
				printf("%d",s);
				return 0;
			}
			
			for(int i=0;i<4;i++)
			{
				int new_x = pick.x+D[0][i];
				int new_y = pick.y+D[1][i];
				
				if(new_x < 1 || new_y < 1 || new_x > N || new_y > M || !map[new_x][new_y])
					continue;
				
				map[new_x][new_y]=0;
				t.x=new_x;
				t.y=new_y;
				push(t);
				k++;
			}
		}
	}
}
