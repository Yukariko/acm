#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DAY[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int YEAR[333];

char a[31];
char year[15];
char month[5];
char day[5];

long long nYear;
long long num;

int nLen;

int isleaf(long long y){return !(y%4||(y%100==0&&y%400));}
long long min(long long p,long long q){return p>q?q:p;}
int cmp(const void *p,const void *q){return *(int *)p-*(int *)q;}

long long makeNum(long long y,int m,int d)
{
	if(m == 2 && d == 29 && !isleaf(y))
		return -1;
	return y * 10000 + m * 100 + d;
}

int getPalin(int find, int len)
{
	int ret = find;

	if(len & 1)
		find /= 10;

	for(int i=len/2;i;i--)
	{
		ret *= 10;
		ret += find % 10;
		find /= 10;
	}
	return ret;
}

int upper_bound(int find)
{
	int start = 0, end = 330;

	while(start <= end)
	{
		int mid = (start + end) / 2;
		if(YEAR[mid] >= find)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return start == 331? -1: start;
}


void init()
{
	for(int i=1,k=0;i<=12;i++)
		for(int j=1;j<=DAY[i];j++)
			if(j%10)
				YEAR[k++] = ((j%10) * 10 + (j/10)) * 100 + (i%10) * 10 + i/10;
	qsort(YEAR,331,4,cmp);
}

void setting()
{
	strcpy(day,strtok(a,"/"));
	strcpy(month,strtok(0,"/"));
	strcpy(year,strtok(0,"/"));
	
	int nMonth;
	int nDay;
	nYear = atoll(year);
	nMonth = atoi(month);
	nDay = atoi(day);
	num = makeNum(nYear,nMonth,nDay);
	nLen = strlen(year+4);

	sprintf(day,"%.2d",nDay);
	sprintf(month,"%.2d",nMonth);
}
long long solve();
long long getNum(int md);

int main()
{
	init();
	int T;
	scanf("%d ",&T);
	while(T--)
	{
		gets(a);
		setting();
		long long ret = solve();

		printf("%.2lld/%.2lld/%lld\n",ret % 100, ret / 100 % 100, ret / 10000);
	}
}

long long getNum(int md)
{
	int m = (md % 10) * 10 + (md / 10) % 10;
	int d = ((md / 100) % 10) * 10 + (md / 1000);

	int len =	nLen;

	int palin = 0;

	long long base = md;

	for(int i=0;i<len;i++)
		base *= 10;

	int next = 1;
	for(int i=len?(len-1)/2:-1;i>=0;i--)
		next *= 10;

	for(;;palin++)
	{
		if(palin == next)
		{
			next *= 10;
			base *= 10;
			palin = 0;
			len++;
		}

		int find = getPalin(palin, len);
		long long ret = makeNum(base + find,m,d);
		if(ret > num)
			return ret; 
	}
}


long long solve()
{
	long long ret = 1LL<<60;

	if(nYear >= 1000)
	{
		char t[5]={};
		strncpy(t,year,4);
		int tyear = atoi(t);

		int next = upper_bound(tyear);

		if(next != -1)
		{
			ret = min(ret, getNum(YEAR[next]));
			if(next + 1 != 331)
				ret = min(ret, getNum(YEAR[next+1]));
			else
				ret = min(ret, getNum(YEAR[0]));
		}
		else
		{
			ret = min(ret, getNum(YEAR[0]));
		}
		return ret;
	}
	else
	{
		char t[11];
		int len = sprintf(t,"%s%s%s",year,month,day);

		char tt[5]={};
		strncpy(tt,t,4);
		int tyear = atoi(tt);
		
		for(int palin = upper_bound(tyear);;palin++)
		{
			if(palin == 331)
			{
				palin = 0;
				len++;
			}

			int md = YEAR[palin];
			
			int find = getPalin(md / (len < 7 ? 10 : 1), len);
			int d = find % 100;
			int m = find / 100 % 100;

			if(m > 12 || m < 1 || d < 1 || d > DAY[m])
				continue;
			if(m == 2 && d == 29 && !isleaf(find / 10000))
				continue;
			if(find > num)
				return find; 
		}
	}
}