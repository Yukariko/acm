#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int rData;
typedef struct Node {
	rData sum, cnt;
}	Node;
typedef struct Rectangle {
	rData x1,y1;
	rData x2,y2;
} Rectangle;

typedef struct line {
	rData x;
	rData y1,y2;
	int type;
} Line;

int rcmp(const void *p, const void *q)
{
	return *(rData *)p>*(rData *)q? 1: *(rData *)p<*(rData *)q? -1: 0;
}

int binsearch(rData *a, int N, rData find)
{
	int start = 0, end = N-1;
	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(a[mid] < find)
			start = mid + 1;
		else if(a[mid] > find)
			end = mid - 1;
		else
			return mid;
	}
	return start;
}

void l_push(Line *l, rData x, rData y1, rData y2, int type)
{
	l->x = x;
	l->y1 = y1;
	l->y2 = y2;
	l->type = type;
}

Node *BT;
rData *y;

void rSet(int pos, int goalLeft,int goalRight, int left, int right, int type)
{
	if(right < goalLeft || goalRight < left)
		return;
	if(goalLeft <= left && right <= goalRight)
		BT[pos].cnt += type;
	else
	{
		int mid = (left + right) / 2;
		rSet(pos * 2, goalLeft, goalRight, left, mid, type);
		rSet(pos * 2 + 1, goalLeft, goalRight, mid+1, right, type);
	}

	if(BT[pos].cnt == 0)
		BT[pos].sum = BT[pos*2].sum + BT[pos*2+1].sum;
	else
		BT[pos].sum = y[right+1] - y[left];
}

rData plane_sweeping(Rectangle *rec, int len)
{
	Line l[2*len];
	y = (rData *)malloc(sizeof(rData) * (len * 2));
	for(int i=0;i<len;i++)
	{
		l_push(&l[i*2], rec[i].x1, rec[i].y1, rec[i].y2, 1);
		l_push(&l[i*2+1], rec[i].x2, rec[i].y1, rec[i].y2, -1);
		y[i*2] = rec[i].y1;
		y[i*2+1] = rec[i].y2;
	}

	int N = len * 2;
	qsort(l,N,sizeof(Line),rcmp);
	qsort(y,N,sizeof(rData),rcmp);

	int sz = 1;
	while(sz < N)
		sz *= 2;

	BT = (Node *)malloc(sizeof(Node) * sz * 4);
	memset(BT,0,sizeof(Node) * sz * 4);

	rData ret = 0;
	rData t = l[0].x;
	rData bT = 0;

	for(int i=0;i<N;i++)
	{
		int ly = 0;
		int ry = binsearch(y, N, l[i].y2);

		rSet(1, ly, ry-1, 0, N-2, l[i].type);

		if(BT[1].sum != bT && (i == N-1 || l[i].x != l[i+1].x))
			printf("%d %d ",l[i].x, BT[1].sum);

		bT = BT[1].sum;		
	}
	return ret;
}

int main()
{
	Rectangle rec[100001];
	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		rec[i].y1 = 0;
		scanf("%d%d%d",&rec[i].x1,&rec[i].y2,&rec[i].x2);
	}

	plane_sweeping(rec,N);
	return 0;
}