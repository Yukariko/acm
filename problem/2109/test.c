typedef struct task {
	int d,p;
} task;

int cmp(task *p, task *q){return p->d - q->d;}
int max(int a,int b){return a>b?a:b;}

main()
{
	int N;
    task T[10001];
	char ck[10001];
    
    memset(ck,0,sizeof(ck));
	scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%d%d",&T[i].p,&T[i].d);
	qsort(T,N,sizeof(task),cmp);
	int ret=0, pos=N-1;
	for(int curDay=T[N-1].d;curDay;--curDay)
	{
		for(;pos >= 0 && T[pos].d >= curDay;--pos);
		pos++;
		int sel=-1;
		for(int i=pos; i < N;++i)
		{
			if(!ck[i])
			{
				sel = sel == -1 || T[sel].p < T[i].p? i: sel;
			}
		}
		if(sel != -1)
		{
			ck[sel] = 1;
			ret += T[sel].p;
		}
	}
	printf("%d",ret);
}
