#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(p,q) (p>q?p:q)

typedef long long rData;
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

int lcmp(const void *p, const void *q)
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

rData plane_sweeping(Rectangle *rec, int len)
{
	Line l[2*len];
	rData y[2*len];
	for(int i=0;i<len;i++)
	{
		l_push(&l[i*2], rec[i].x1, rec[i].y1, rec[i].y2, 1);
		l_push(&l[i*2+1], rec[i].x2, rec[i].y1, rec[i].y2, -1);
		y[i*2] = rec[i].y1;
		y[i*2+1] = rec[i].y2;
	}

	int N = len * 2;
	qsort(l,N,sizeof(Line),lcmp);
	qsort(y,N,sizeof(rData),rcmp);

	int ck[N];
	memset(ck,0,sizeof(ck));
	
	rData ret = 0;
	int t = l[0].x;
	for(int i=0;i<N;i++)
	{
		int ly = binsearch(y, N, l[i].y1);
		int ry = binsearch(y, N, l[i].y2);

		for(int j=1; j < N; j++)
			if(ck[j])
				ret += (l[i].x - t) * (y[j] - y[j-1]);

		for(int j=ly+1; j <= ry; j++)
			ck[j] += l[i].type;

		t = l[i].x;
	}

	return ret;
}

int main()
{
	Rectangle rec[1001];

	int T;
	scanf("%d",&T);

	for(;T--;)
	{
		int N;
		scanf("%d",&N);

		for(int i=0;i<N;i++)
			scanf("%lld%lld%lld%lld",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);

		printf("%lld\n",plane_sweeping(rec,N));
	}
	return 0;
}