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
	for(int i=0;i<len;i++)
	{
		l_push(&l[i*2], rec[i].x1, rec[i].y1, rec[i].y2, 1);
		l_push(&l[i*2+1], rec[i].x2, rec[i].y1, rec[i].y2, -1);
	}

	int N = len * 2;
	qsort(l,N,sizeof(Line),lcmp);

	int ck[30001];
	memset(ck,0,sizeof(ck));

	const int tok = 100;
	const int pCount = 30001 /tok + 1;
	int pack[pCount];
	memset(pack,0,sizeof(pack));

	rData ret = 0;
	int t = l[0].x;
	for(int i=0;i<N;i++)
	{
		int ly = l[i].y1;
		int ry = l[i].y2;

		for(int j=0; j < pCount; j++)
		{
			if(pack[j])
			{
				for(int k=0; k < tok; k++)
					if(ck[j*tok+k])
						ret += (l[i].x - t);
			}
		}

		for(int j=ly; j < ry; j++)
		{
			ck[j] += l[i].type;
			pack[j/tok] += l[i].type;
		}

		t = l[i].x;
	}

	return ret;
}

int main()
{
	Rectangle rec[10001];
	int N;
	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%lld%lld%lld%lld",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);

	printf("%lld\n",plane_sweeping(rec,N));
	return 0;
}